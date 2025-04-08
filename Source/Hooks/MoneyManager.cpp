//
// Created by kibbe on 2025-04-04.
//

#include "pch.h"

bool __fastcall Hook::MoneyManager::hkCreateOnlineTransaction(ScheduleOne_Money_MoneyManager_o* pThis, System_String transactionName, float amount, float quantity, System_String transactionNote) {
    static auto oCreateOnlineTransaction = reinterpret_cast <decltype(&hkCreateOnlineTransaction)>(pCreateOnlineTransaction);

    G::m_iMoneyManager = pThis;

    std::cout << "Created Transaction: " << transactionName.ToString() << " (" << amount << " x" << quantity << ") " << transactionNote.ToString() << std::endl;

    return oCreateOnlineTransaction(pThis, transactionName, amount, quantity, transactionNote);
}
