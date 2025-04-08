//
// Created by kibbe on 2025-04-04.
//

#include "pch.h"

bool Hook::Init() {
    CREATE_HOOK(UnityHelpers::FindMethod("CreateOnlineTransaction"),
        MoneyManager::pCreateOnlineTransaction, MoneyManager::hkCreateOnlineTransaction);
    CREATE_HOOK(UnityHelpers::FindMethodByClass("Update", "MoneyManager"),
        MoneyManager::pUpdate, MoneyManager::hkUpdate);

    CREATE_HOOK(UnityHelpers::FindMethodByClass("Update", "TimeManager"),
        TimeManager::pUpdate, TimeManager::hkUpdate);

    CREATE_HOOK(UnityHelpers::FindMethodByClass("Update", "PlayerInventory"),
        PlayerInventory::pUpdate, PlayerInventory::hkUpdate);

    CREATE_HOOK(UnityHelpers::FindMethod("AreAllPlayersReadyToSleep"),
        Player::pAreAllPlayersReadyToSleep, Player::hkAreAllPlayersReadyToSleep);

    CREATE_HOOK(UnityHelpers::FindMethodByClass("CanShoot", "PursuitBehaviour"),
        PursuitBehaviour::pCanShoot, PursuitBehaviour::hkCanShoot);

    CREATE_HOOK(UnityHelpers::FindMethodByClass("GetBetFromSliderValue", "BlackjackInterface"),
        BlackjackInterface::pGetBetFromSliderValue, BlackjackInterface::hkGetBetFromSliderValue);

    MH_EnableHook(MH_ALL_HOOKS);

    return true;
}
