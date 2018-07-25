//
// Created by Svetlana Matculevich on 27/06/2017.
//

#include "AccountImpl.h"

int AccountImpl::maxAccountNumUsed; // definition  of the statics

AccountImpl::AccountImpl(int bal, Customer* cust) :
        balance(bal),
        customer(cust),
        accountnum(++maxAccountNumUsed),
        log(accountnum){};

int AccountImpl::Deposit(int amount){
    log.AddDeposit(BuildDateStringForToday(), amount);
    balance += amount;
    return balance;
}
int AccountImpl::Withdraw(int amount){
    log.AddWithdrawal(BuildDateStringForToday(), amount);
    balance -= amount;
    return balance;
}

std::string AccountImpl::BuildDateStringForToday(){
    return "today";
}