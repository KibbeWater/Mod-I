//
// Created by kibbe on 2025-04-08.
//

#include "Customer.h"

namespace GameAPI {
    ScheduleOne_Economy_Customer_c *Customer::GetCustomerClass() {
        static ScheduleOne_Economy_Customer_c *instance = reinterpret_cast<ScheduleOne_Economy_Customer_c *>(
            IL2CPP::Class::Find("ScheduleOne.Economy.Customer"));

        return instance;
    }

    Customer::Customer(ScheduleOne_Economy_Customer_o *instance) {
        this->_instance = instance;
    }

    std::vector<Customer> Customer::GetUnlockedCustomers() {
        std::vector<Customer> customers = {};

        auto customerList = GetCustomerClass()->static_fields->UnlockedCustomers;
        for (int i = 0; i < customerList->fields._size; ++i) {
            auto customer = customerList->fields._items->m_Items[i];
            if (customer == nullptr) continue;

            customers.push_back(customer);
        }

        return customers;
    }


    typedef void (*fRequestProduct)(ScheduleOne_Economy_Customer_o *pThis);

    void Customer::RequestProduct() {
        static fRequestProduct oRequestProduct = reinterpret_cast<fRequestProduct>(
            UnityHelpers::FindMethodByClass("RequestProduct", "Customer")->m_pMethodPointer);

        auto instance = this->_instance;
        game_thread::execute([instance] {
            oRequestProduct(instance);
        });
    }
} // GameAPI
