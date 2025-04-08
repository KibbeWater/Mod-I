//
// Created by kibbe on 2025-04-09.
//

#ifndef PLAYERINVENTORYHOOK_H
#define PLAYERINVENTORYHOOK_H

namespace Hook
{
    namespace PlayerInventory
    {
        inline void* pUpdate;
        void hkUpdate(ScheduleOne_PlayerScripts_PlayerInventory_o* pThis);
    }
}

#endif //PLAYERINVENTORYHOOK_H
