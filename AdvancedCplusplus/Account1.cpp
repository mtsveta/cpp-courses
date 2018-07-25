//
// Created by Svetlana Matculevich on 27/06/2017.
//

#include "Account1.h"

int Account1::maxAccountNumUsed; // definition  of the statics
// statics must be defined here

Account1::Account1(int bal, Customer* cust) :
        balance(bal), customer(cust), accountnum(++maxAccountNumUsed), log(accountnum){};

int Account1::Deposit(int amount){
    log.AddDeposit(BuildDateStringForToday(), amount);
    balance += amount;
    return balance;
}
int Account1::Withdraw(int amount){
    log.AddWithdrawal(BuildDateStringForToday(), amount);
    balance -= amount;
    return balance;
}

std::string Account1::BuildDateStringForToday(){
    // need work
    return "today";
}
