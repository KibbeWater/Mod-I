//
// Created by kibbe on 2025-04-07.
//

#include "pch.h"

bool Hook::Player::hkAreAllPlayersReadyToSleep() {
    static auto oAreAllPlayersReadyToSleep = reinterpret_cast <decltype(&hkAreAllPlayersReadyToSleep)>(pAreAllPlayersReadyToSleep);

    auto player = GameAPI::Player::GetLocalPlayer();
    if (!player) return false;

    auto playerList = GameAPI::Player::GetAllPlayers();
    for (auto player : playerList) {
        if (!player.IsReadyToSleep()) player.SetReadyToSleep(true);
    }

    return player->IsReadyToSleep();

    // return oAreAllPlayersReadyToSleep();
}
