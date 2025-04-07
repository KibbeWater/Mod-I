#include "pch.h"

void Update() {
    game_thread::_processQueue();
}

DWORD WINAPI OnDllAttach(LPVOID lpParameter) {
    HWND mainWin = FindWindowW(
        L"UnityWndClass",
        L"Schedule I"
    );

    IL2CPP::Initialize();
    IL2CPP::Callback::Initialize();
    IL2CPP::Callback::OnUpdate::Add((void*)Update);

    UnityHelpers::Initialize();

    ImplHookDX11_Init(mainWin);

    if (!Hook::Init()) {
        std::cout << "Failed to initialize hooks." << std::endl;
    }

    return 0;
}

// DllMain: the entry point for the DLL.
BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved) {
    AllocConsole();
    freopen("CONOUT$", "w", stdout);

    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            ::DisableThreadLibraryCalls(hModule);
            ::CreateThread(nullptr, 0, OnDllAttach, hModule, 0, nullptr);
            break;

        default:
            break;
    }
    return TRUE;
}
