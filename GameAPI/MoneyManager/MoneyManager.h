//
// Created by kibbe on 2025-04-04.
//

#ifndef MONEYMANAGER_H
#define MONEYMANAGER_H

namespace GameAPI {
    namespace MoneyManager {
        int GetCash();
        void ChangeCash(int addValue);

        int GetBalance();
        void ChangeBalance(int addValue);
    }
}

#endif //MONEYMANAGER_H
