//
// Created by kibbe on 2025-04-08.
//

#include <codecvt>
#include <iostream>
#include <locale>
#include <thread>
#include <BlackBone/Process/Process.h>

using namespace blackbone;

std::wstring GetWString(const std::string& str)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.from_bytes(str);
}

std::string GetString(const std::wstring& wstr)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;

    return converterX.to_bytes(wstr);
}

int main( int argc, char* argv[] ) {
    // Check for minimum required arguments.
    if (argc < 2) {
        std::cout << "Usage: " << argv[0]
                  << " <executable_path> --target <DLL_path> [--module <module_name>] [--timeout <timeout_in_ms>]\n";
        return EXIT_FAILURE;
    }

    // arg0: The executable path.
    std::wstring executablePath = GetWString(argv[1]);

    std::string dllPath;
    std::wstring moduleName;   // Optional: Module name to wait for.
    int timeoutMs = 0;        // Optional: Timeout in milliseconds (0 = no timeout).

    // Parse the remaining command-line arguments.
    for (int i = 2; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--target" && i + 1 < argc) {
            dllPath = argv[++i];
        } else if (arg == "--module" && i + 1 < argc) {
            moduleName = GetWString(argv[++i]);
        } else if (arg == "--timeout" && i + 1 < argc) {
            try {
                timeoutMs = std::stoi(argv[++i]);
            } catch (const std::exception& e) {
                std::cerr << "Invalid timeout value.\n";
                return EXIT_FAILURE;
            }
        }
    }

    if (dllPath.empty()) {
        std::cerr << "Error: --target argument is required.\n";
        return EXIT_FAILURE;
    }

    Process *process = new Process();
    process->CreateAndAttach(executablePath);

    // If a module name is specified, wait until it is loaded.
    if (!moduleName.empty()) {
        std::cout << "Waiting for module '" << GetString(moduleName) << "' to load...\n";
        auto startTime = std::chrono::steady_clock::now();
        const int pollIntervalMs = 100;
        bool moduleLoaded = false;
        while (true) {
            if (process->modules().GetModule(moduleName)) {
                moduleLoaded = true;
                break;
            }
            if (timeoutMs > 0) {
                auto now = std::chrono::steady_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime).count();
                if (elapsed >= timeoutMs) {
                    break;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(pollIntervalMs));
        }
        if (!moduleLoaded) {
            std::cerr << "Timeout waiting for module '" << GetString(moduleName) << "' to load.\n";
            return EXIT_FAILURE;
        }
    }

    // Proceed to inject the DLL.
    if (process->modules().Inject(GetWString(dllPath))) {
        std::cout << "DLL injected successfully.\n";
    } else {
        std::cerr << "DLL injection failed.\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
