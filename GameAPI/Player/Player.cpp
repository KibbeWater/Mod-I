//
// Created by kibbe on 2025-04-07.
//

#include "Player.h"

namespace GameAPI {
    ScheduleOne_PlayerScripts_Player_c * Player::GetPlayerClass() {
        static ScheduleOne_PlayerScripts_Player_c *instance = reinterpret_cast<ScheduleOne_PlayerScripts_Player_c*>(
            IL2CPP::Class::Find("ScheduleOne.PlayerScripts.Player"));

        return instance;
    }

    Player::Player(ScheduleOne_PlayerScripts_Player_o *instance) {
        this->_instance = instance;
    }

    std::vector<Player> Player::GetAllPlayers() {
        std::vector<Player> players = {};

        auto playerList = GetPlayerClass()->static_fields->PlayerList;
        for (int i = 0; i < playerList->fields._size; ++i) {
            auto player = playerList->fields._items->m_Items[i];
            if (player == nullptr) continue;

            players.push_back(player);
        }

        return players;
    }

    Player* Player::GetLocalPlayer() {
        auto local = GetPlayerClass()->static_fields->Local;
        if (!local) return nullptr;

        return new Player(local);
    }

    bool Player::IsLocalPlayer() {
        auto networkObject = this->_instance->fields._networkObjectCache->fields;

        auto owner = networkObject._owner;
        if (owner == nullptr) return false;

        bool IsClientInitialized = networkObject._IsClientInitialized_k__BackingField;
        bool IsLocalClient = !(owner->fields._NetworkManager_k__BackingField == nullptr) && owner->fields.
                             _NetworkManager_k__BackingField->fields._ClientManager_k__BackingField->fields.Connection->
                             fields.ClientId == owner->fields.ClientId;

        return IsClientInitialized && IsLocalClient;
    }

    bool Player::IsReadyToSleep() {
        return this->_instance->fields._IsReadyToSleep_k__BackingField;
    }

    typedef void (*fWriteSetReadyToSleep)(ScheduleOne_PlayerScripts_Player_o *pThis, bool ready);
    void Player::SetReadyToSleep(bool readyToSleep) {
        auto instance = this->_instance;
        auto klass = this->_instance->klass;
        game_thread::execute([instance, readyToSleep, klass] {
            static auto rpcWriter = reinterpret_cast<fWriteSetReadyToSleep>(UnityHelpers::FindRPCMethod(
                UnityHelpers::Writer,
                reinterpret_cast<Unity::il2cppClass*>(klass),
                "SetReadyToSleep"
                )->m_pMethodPointer);

            rpcWriter(instance, readyToSleep);
        });
    }
} // GameAPI
