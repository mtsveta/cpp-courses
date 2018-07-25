//
// Created by Svetlana Matculevich on 27/06/2017.
//

#ifndef DEMOS_ACCOUNT1_H
#define DEMOS_ACCOUNT1_H

#pragma once
#include "TransactionLog.h"

// forward declaration
class Customer;

class Account1 {

private:
    int balance;
    int accountnum;
    static int maxAccountNumUsed;
    // declaration of the statics
    // shared a classed member variable Account1::maxAccountNumUsed
    // all the individual instances of the Account1 share this number
    // it belongs to the class rather then the instance
    // statics are initilized with 0

    TransactionLog log; // whenever the account is constracted => the log will be constructed too
    // whenever the account goes our of scope => log goes out of scope

    Customer* customer; // for access to methods
    // we include the pointer to the customer not to store all the infomation and methods about him/her

    std::string BuildDateStringForToday(); // private, inaccessable from the outside
    // we use it only when we are trying to initilize the Account
    // so we can access it from the contructor


public:
    Account1(int bal, Customer* cust);
    int Deposit(int amount);
    int Withdraw(int amount);
};


#endif //DEMOS_ACCOUNT1_H
