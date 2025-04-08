//
// Created by kibbe on 2025-04-04.
//

#include "pch.h"

bool Hook::Init() {
    if (MH_CreateHook(UnityHelpers::FindMethod("CreateOnlineTransaction")->m_pMethodPointer,
                      (LPVOID) &MoneyManager::hkCreateOnlineTransaction,
                      &MoneyManager::pCreateOnlineTransaction) != MH_OK) { return false; }
    if (MH_CreateHook(UnityHelpers::FindMethodByClass("Update", "TimeManager")->m_pMethodPointer,
                      (LPVOID) &TimeManager::hkUpdate, &TimeManager::pUpdate) != MH_OK) { return false; }
    if (MH_CreateHook(UnityHelpers::FindMethod("AreAllPlayersReadyToSleep")->m_pMethodPointer,
                      (LPVOID) &Player::hkAreAllPlayersReadyToSleep, &Player::pAreAllPlayersReadyToSleep) != MH_OK) {
        return false;
    }

    MH_EnableHook(MH_ALL_HOOKS);

    return true;
}
