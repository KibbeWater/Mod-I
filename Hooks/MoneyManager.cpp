//
// Created by kibbe on 2025-04-04.
//

#include "pch.h"

bool Hook::MoneyManager::hkCreateOnlineTransaction(ScheduleOne_Money_MoneyManager_o* pThis, System_String* transactionName, float amount, float quantity, System_String* transactionNote) {
    static auto oCreateOnlineTransaction = reinterpret_cast <decltype(&hkCreateOnlineTransaction)>(pCreateOnlineTransaction);

    std::cout << "Created Transaction: " << transactionName->ToString() << " (" << amount << " x" << quantity << ") " << transactionNote->ToString() << std::endl;

    return oCreateOnlineTransaction(pThis, transactionName, amount, quantity, transactionNote);
}

void Hook::MoneyManager::hkUpdate(ScheduleOne_Money_MoneyManager_o *pThis) {
    G::m_iMoneyManager = pThis;
}

