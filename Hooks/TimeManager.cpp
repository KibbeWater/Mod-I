//
// Created by kibbe on 2025-04-07.
//

#include "pch.h"

void __fastcall Hook::TimeManager::hkUpdate(ScheduleOne_GameTime_TimeManager_o *pThis) {
    static auto oUpdate = reinterpret_cast<decltype(&hkUpdate)>(pUpdate);

    return oUpdate(pThis);
}
