//
// Created by kibbe on 2025-04-04.
//

#include "Hook.h"

bool Hook::Init() {
    if (MH_CreateHook(
            MEM::PatternScan("GameAssembly.dll",
                             "48 89 5C 24 ? 48 89 6C 24 ? 56 48 83 EC ? 80 3D ? ? ? ? ? 48 8B EA 0F 29 74 24 ? 48 8B D9 0F 29 7C 24"),
            (LPVOID)&MoneyManager::hkCreateOnlineTransaction, (LPVOID*)&MoneyManager::pCreateOnlineTransaction) != MH_OK) {
        return false;
    }

    MH_EnableHook(MH_ALL_HOOKS);

    return true;
}
