//
// Created by kibbe on 2025-04-04.
//

#include "pch.h"

typedef void (*fChangeCashBalance)(ScheduleOne_Money_MoneyManager_o *pThis, float change, bool visualizeChange, bool playSound);

void GameAPI::MoneyManager::ChangeBalance(int addValue) {
    static fChangeCashBalance oChangeCashBalance = reinterpret_cast<fChangeCashBalance>(MEM::PatternScan("GameAssembly.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 80 3D ? ? ? ? ? 41 0F B6 F1 44 0F 29 44 24"));

    float _val = static_cast<float>(addValue);

    game_thread::execute([&]() {
        oChangeCashBalance(G::m_iMoneyManager, _val, true, true);
    });
}
