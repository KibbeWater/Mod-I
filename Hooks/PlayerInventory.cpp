//
// Created by kibbe on 2025-04-09.
//

#include "pch.h"

void Hook::PlayerInventory::hkUpdate(ScheduleOne_PlayerScripts_PlayerInventory_o* pThis) {
    ORIGINAL_HOOK(Update);

    G::m_iPlayerInventory = pThis;

    return oUpdate(pThis);
}

