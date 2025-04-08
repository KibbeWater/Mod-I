//
// Created by kibbe on 2025-04-08.
//

#include "CashInstance.h"

namespace GameAPI {
    ScheduleOne_ItemFramework_CashInstance_c* CashInstance::GetCashInstanceClass() {
        static ScheduleOne_ItemFramework_CashInstance_c *instance = reinterpret_cast<ScheduleOne_ItemFramework_CashInstance_c *>(
            IL2CPP::Class::Find("ScheduleOne.ItemFramework.CashInstance"));

        return instance;
    }

    CashInstance::CashInstance(ScheduleOne_ItemFramework_CashInstance_o *instance) {
        this->_instance = instance;
    }

    int CashInstance::GetBalance() {
        return this->_instance->fields._Balance_k__BackingField;
    }

    typedef void (*fChangeBalance)(ScheduleOne_ItemFramework_CashInstance_o *pThis, float addValue);
    void CashInstance::AddBalance(int addValue) {
        static fChangeBalance oChangeBalance = reinterpret_cast<fChangeBalance>(
           UnityHelpers::FindMethodByClass("ChangeBalance", "CashInstance")->m_pMethodPointer);

        auto instance = this->_instance;
        game_thread::execute([instance, addValue] {
            float _val = static_cast<float>(addValue);
            oChangeBalance(instance, _val);
        });
    }
} // GameAPI