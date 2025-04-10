//
// Created by kibbe on 4/3/2025.
//

#ifndef GLOBALS_H
#define GLOBALS_H

namespace G {
    inline ID3D11Device* g_pd3dDevice = nullptr;

    // Subsystems
    inline ScheduleOne_Money_MoneyManager_o*            m_iMoneyManager = nullptr;
    inline ScheduleOne_PlayerScripts_PlayerInventory_o* m_iPlayerInventory = nullptr;
    inline ScheduleOne_GameTime_TimeManager_o*          m_iGameTimeManager = nullptr;
}

namespace F {
    inline bool m_bOnePlayerSleep = true;
}

#endif //GLOBALS_H
