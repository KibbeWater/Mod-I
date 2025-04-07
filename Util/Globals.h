//
// Created by kibbe on 4/3/2025.
//

#ifndef GLOBALS_H
#define GLOBALS_H

namespace G {
    inline ID3D11Device* g_pd3dDevice = nullptr;

    // Subsystems
    inline ScheduleOne_Money_MoneyManager_o* m_iMoneyManager = nullptr;
    inline bool m_bAdd10k = false;
}

#endif //GLOBALS_H
