//
// Created by kibbe on 2025-04-08.
//

#ifndef CASHINSTANCE_H
#define CASHINSTANCE_H

namespace GameAPI {

class CashInstance {
    static ScheduleOne_ItemFramework_CashInstance_c* GetCashInstanceClass();

    ScheduleOne_ItemFramework_CashInstance_o* _instance;

public:
    CashInstance(ScheduleOne_ItemFramework_CashInstance_o* instance);

    int GetBalance();
    void AddBalance(int addValue);
};

} // GameAPI

#endif //CASHINSTANCE_H
