//
// Created by kibbe on 2025-04-04.
//

#include "pch.h"

typedef void (*fChangeCashBalance)(ScheduleOne_Money_MoneyManager_o *pThis, float change, bool visualizeChange, bool playSound);

int GameAPI::MoneyManager::GetCash() {
    if (G::m_iPlayerInventory == nullptr) return 0;

    PlayerInventory player_inventory = PlayerInventory(G::m_iPlayerInventory);
    return player_inventory.GetCashInstance()->GetBalance();
}

void GameAPI::MoneyManager::ChangeCash(int addValue) {
    static fChangeCashBalance oChangeCashBalance = reinterpret_cast<fChangeCashBalance>(
        UnityHelpers::FindMethodByClass("ChangeCashBalance", "MoneyManager")->m_pMethodPointer);

    game_thread::execute([addValue] {
        float _val = static_cast<float>(addValue);
        oChangeCashBalance(G::m_iMoneyManager, _val, true, true);
    });
}

int GameAPI::MoneyManager::GetBalance() {
    if (G::m_iMoneyManager == nullptr) return 0;
    return static_cast<int>(G::m_iMoneyManager->fields.onlineBalance);
}

void GameAPI::MoneyManager::ChangeBalance(int addValue) {
    game_thread::execute([addValue] {
        Unity::System_String* name = IL2CPP::String::New("Spawned Money");
        Unity::System_String* note = IL2CPP::String::New("Cheated Money");

        float _val = static_cast<float>(addValue);
        Hook::MoneyManager::hkCreateOnlineTransaction(G::m_iMoneyManager, reinterpret_cast<System_String*>(name), _val, 1, reinterpret_cast<System_String*>(note));
    });
}
