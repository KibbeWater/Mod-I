//
// Created by kibbe on 2025-04-04.
//

#ifndef MONEYMANAGERHOOKS_H
#define MONEYMANAGERHOOKS_H

namespace Hook
{
    namespace MoneyManager
    {
        inline void* pCreateOnlineTransaction;
        bool __fastcall hkCreateOnlineTransaction(ScheduleOne_Money_MoneyManager_o* pThis, System_String transactionName, float amount, float quantity, System_String transactionNote);
    }
}

#endif //MONEYMANAGER_H
