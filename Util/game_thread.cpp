//
// Created by kibbe on 2025-04-05.
//

#include "game_thread.h"

// Global handle to the game thread (must be obtained appropriately).
static HANDLE g_gameThread = nullptr;
static DWORD g_gameThreadId = 0;

// Global variable to hold the lambda to execute.
std::function<void()> g_lambda = nullptr;

// Global backup of the original thread context.
CONTEXT g_backup = {};

// An event used to signal that our lambda has finished executing.
HANDLE g_lambdaExecutedEvent = nullptr;

// This function calls the lambda and signals its completion.
void ExecuteLambdaAndSignal() {
    if (g_lambda) {
        std::cout << "Executing Lambda on game thread..." << std::endl;
        g_lambda();
        std::cout << "Finished executing Lambda on game thread." << std::endl;
    }
    // Signal that the lambda has finished.
    SetEvent(g_lambdaExecutedEvent);
}

// A trampoline function that will be executed on the game thread.
// It simply calls our lambda helper and then goes into an infinite sleep.
// The infinite sleep is expected to be interrupted later when we suspend the thread to restore its original context.
extern "C" __declspec(noinline) void Trampoline() {
    std::cout << "Running trampoline function..." << std::endl;
    ExecuteLambdaAndSignal();
    // Prevent returning normally. The thread should be suspended and its context restored.
    Sleep(INFINITE);
}

// Executes a given lambda on the game thread.
// This function suspends the thread, modifies its context to run our trampoline, resumes it so our lambda executes,
// then waits until the lambda is done, suspends the thread again, restores its original context, and resumes it.
bool game_thread::execute(const std::function<void()> &lambda) {
    if (!g_gameThread) {
        std::cerr << "Game thread handle is not set." << std::endl;
        return false;
    }
    g_lambda = lambda;
    if (!g_lambdaExecutedEvent) {
        g_lambdaExecutedEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
        if (!g_lambdaExecutedEvent) {
            std::cerr << "Failed to create event." << std::endl;
            return false;
        }
    }

    // Suspend the game thread and back up its context.
    if (SuspendThread(g_gameThread) == (DWORD) -1) {
        std::cerr << "Failed to suspend game thread." << std::endl;
        return false;
    }

    CONTEXT ctx = {};
    ctx.ContextFlags = CONTEXT_FULL;
    if (!GetThreadContext(g_gameThread, &ctx)) {
        ResumeThread(g_gameThread);
        std::cerr << "Failed to get thread context." << std::endl;
        return false;
    }
    // Backup the original context so we can restore it later.
    g_backup = ctx;

    // Modify the thread's context so that its RIP points to our trampoline.
#ifdef _M_X64
    ctx.Rip = reinterpret_cast<DWORD64>(&Trampoline);
#else
#error "This implementation is for x64."
#endif

    if (!SetThreadContext(g_gameThread, &ctx)) {
        ResumeThread(g_gameThread);
        std::cerr << "Failed to set thread context." << std::endl;
        return false;
    }

    // Resume the thread so it begins executing our trampoline.
    if (ResumeThread(g_gameThread) == (DWORD) -1) {
        std::cerr << "Failed to resume game thread." << std::endl;
        return false;
    }

    // Wait for our lambda to complete its execution.
    WaitForSingleObject(g_lambdaExecutedEvent, INFINITE);

    // Now that our lambda has run, suspend the game thread again.
    if (SuspendThread(g_gameThread) == (DWORD) -1) {
        std::cerr << "Failed to suspend game thread after lambda execution." << std::endl;
        return false;
    }

    // Restore the original thread context.
    if (!SetThreadContext(g_gameThread, &g_backup)) {
        ResumeThread(g_gameThread);
        std::cerr << "Failed to restore thread context." << std::endl;
        return false;
    }

    // Resume the thread; it will now continue from its original execution point.
    if (ResumeThread(g_gameThread) == (DWORD) -1) {
        std::cerr << "Failed to resume game thread after restoring context." << std::endl;
        return false;
    }

    return true;
}

bool game_thread::init(DWORD targetProcessId) {
    DWORD bestThreadId = 0;
    ULONGLONG minCreateTime = MAXULONGLONG;

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        std::cerr << "[game_thread] Failed to create thread snapshot." << std::endl;
        return false;
    }

    THREADENTRY32 te{};
    te.dwSize = sizeof(te);

    if (Thread32First(snapshot, &te)) {
        do {
            if (te.th32OwnerProcessID == targetProcessId) {
                HANDLE thread = OpenThread(
                    THREAD_QUERY_INFORMATION | THREAD_SUSPEND_RESUME | THREAD_GET_CONTEXT | THREAD_SET_CONTEXT, FALSE,
                    te.th32ThreadID);
                if (thread) {
                    FILETIME createTime, exitTime, kernelTime, userTime;
                    if (GetThreadTimes(thread, &createTime, &exitTime, &kernelTime, &userTime)) {
                        ULONGLONG ct = ((ULONGLONG) createTime.dwHighDateTime << 32) | createTime.dwLowDateTime;
                        if (ct < minCreateTime) {
                            minCreateTime = ct;
                            bestThreadId = te.th32ThreadID;
                        }
                    }
                    CloseHandle(thread);
                }
            }
        } while (Thread32Next(snapshot, &te));
    }

    CloseHandle(snapshot);

    if (bestThreadId == 0) {
        std::cerr << "[game_thread] Could not find any suitable thread." << std::endl;
        return false;
    }

    HANDLE threadHandle = OpenThread(THREAD_ALL_ACCESS, FALSE, bestThreadId);
    if (!threadHandle) {
        std::cerr << "[game_thread] Failed to open game thread handle." << std::endl;
        return false;
    }

    g_gameThread = threadHandle;
    g_gameThreadId = bestThreadId;

    std::cout << "[game_thread] Found and stored game thread: ID = " << g_gameThreadId << std::endl;
    return true;
}

HANDLE get_handle() {
    return g_gameThread;
}

DWORD game_thread::get_thread_id() {
    return g_gameThreadId;
}
