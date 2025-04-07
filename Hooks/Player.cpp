//
// Created by kibbe on 2025-04-07.
//

#include "pch.h"

bool __fastcall Hook::Player::hkAreAllPlayersReadyToSleep() {
    static auto oAreAllPlayersReadyToSleep = reinterpret_cast <decltype(&hkAreAllPlayersReadyToSleep)>(pAreAllPlayersReadyToSleep);

    auto player = GameAPI::Player::GetLocalPlayer();
    if (!player) return false;

    return player->IsReadyToSleep();

    // return oAreAllPlayersReadyToSleep();
}
