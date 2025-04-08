//
// Created by kibbe on 2025-04-08.
//

#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

namespace GameAPI {

class PlayerInventory {
    static ScheduleOne_PlayerScripts_PlayerInventory_c* GetPlayerInventoryClass();

    ScheduleOne_PlayerScripts_PlayerInventory_o* _instance;

public:
    PlayerInventory(ScheduleOne_PlayerScripts_PlayerInventory_o* instance);

    CashInstance* GetCashInstance();
};

} // GameAPI

#endif //PLAYERINVENTORY_H
