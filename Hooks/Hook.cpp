//
// Created by kibbe on 2025-04-04.
//

#include "pch.h"

bool Hook::Init() {
    CREATE_HOOK_H(MoneyManager, CreateOnlineTransaction)
    CREATE_HOOK_H(MoneyManager, Update);

    CREATE_HOOK_H(TimeManager, Update);

    CREATE_HOOK_H(Equippable_TrashGrabber, GetCapacity);

    CREATE_HOOK_H(Equippable_Cuke, Drink);

    CREATE_HOOK_H(PlayerInventory, Update);

    CREATE_HOOK_H(Player, AreAllPlayersReadyToSleep);

    CREATE_HOOK_H(PursuitBehaviour, CanShoot)

    CREATE_HOOK_H(BlackjackInterface, BetSliderChanged);

    MH_EnableHook(MH_ALL_HOOKS);

    return true;
}
