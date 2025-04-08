//
// Created by kibbe on 2025-04-08.
//

#include "pch.h"

namespace GameAPI {
    ScheduleOne_PlayerScripts_PlayerInventory_c *PlayerInventory::GetPlayerInventoryClass() {
        static ScheduleOne_PlayerScripts_PlayerInventory_c *instance = reinterpret_cast<ScheduleOne_PlayerScripts_PlayerInventory_c *>(
            IL2CPP::Class::Find("ScheduleOne.PlayerScripts.PlayerInventory"));

        return instance;
    }

    PlayerInventory::PlayerInventory(ScheduleOne_PlayerScripts_PlayerInventory_o *instance) {
        this->_instance = instance;
    }

    CashInstance* PlayerInventory::GetCashInstance() {
        return new CashInstance(this->_instance->fields._cashInstance_k__BackingField);
    }
} // GameAPI