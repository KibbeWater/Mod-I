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
        bool hkCreateOnlineTransaction(ScheduleOne_Money_MoneyManager_o* pThis, System_String* transactionName, float amount, float quantity, System_String* transactionNote);

        inline void* pUpdate;
        void hkUpdate(ScheduleOne_Money_MoneyManager_o* pThis);
    }
}

#endif //MONEYMANAGER_H
