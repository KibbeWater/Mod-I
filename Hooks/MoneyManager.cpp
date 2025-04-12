//
// Created by kibbe on 2025-04-04.
//

#include "pch.h"

bool Hook::MoneyManager::hkCreateOnlineTransaction(ScheduleOne_Money_MoneyManager_o* pThis, System_String* transactionName, float amount, float quantity, System_String* transactionNote) {
    ORIGINAL_HOOK(CreateOnlineTransaction);

    std::cout << "Created Transaction: " << transactionName->ToString() << " (" << amount << " x" << quantity << ") " << transactionNote->ToString() << std::endl;

    return oCreateOnlineTransaction(
        pThis, transactionName, amount, quantity, transactionNote);
}

void Hook::MoneyManager::hkUpdate(ScheduleOne_Money_MoneyManager_o *pThis) {
    ORIGINAL_HOOK(Update);

    G::m_iMoneyManager = pThis;

    return oUpdate(pThis);
}

