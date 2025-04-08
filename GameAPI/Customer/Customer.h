//
// Created by kibbe on 2025-04-08.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

namespace GameAPI {

class Customer {
    static ScheduleOne_Economy_Customer_c* GetCustomerClass();

    ScheduleOne_Economy_Customer_o* _instance;

    Customer(ScheduleOne_Economy_Customer_o* instance);

public:
    static std::vector<Customer> GetUnlockedCustomers();

    void RequestProduct();
};

} // GameAPI

#endif //CUSTOMER_H
