//
// Created by Svetlana Matculevich on 27/06/2017.
//
#pragma once
#include "TransactionLog.h"

class Customer;

class AccountImpl {

private:
    int balance;
    int accountnum;
    static int maxAccountNumUsed; // declaration of the statics
    // shared a classed member variable Account1::maxAccountNumUsed
    // all the individual instances of the Account1 share this number, it belongs to the class rather then the instance
    // statics are initilized with 0

    TransactionLog log;
    Customer* customer; // for access to methods
    std::string BuildDateStringForToday();

public:

    AccountImpl(int bal, Customer* cust);
    int Deposit(int amount);
    int Withdraw(int amount);
};

