//
// Created by kibbe on 2025-04-08.
//

#include <iostream>
#include <BlackBone/Process/Process.h>

void main() {
    // Pseudocode example
    auto process = Blackbone::Process(targetProcessPath);
    process.Create(); // Launch the process

    // Wait until the target module appears or timeout occurs
    while (!process.ModuleExists("target_module.dll") && !timeoutReached()) {
        Sleep(pollInterval);
    }

    if (process.ModuleExists("target_module.dll")) {
        process.InjectDLL(dllPath); // Use manual mapping or other injection method
        std::cout << "DLL injected successfully.\n";
    }
    else {
        std::cerr << "Timeout waiting for module to load.\n";
    }
}
