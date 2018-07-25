//
// Created by Svetlana Matculevich on 27/06/2017.
//

#include "Account.h"
#include "AccountImpl.h"
// via this h-file Account know about all the methods of AccountImpl
// implementation of all the functions is now deligated to
// AccountImpl class

Account::Account(int bal, Customer* cust) :
        pImpl(new AccountImpl(bal, cust)) // deligating constrution to the pImpl account
{};

Account::~Account() {}; // we have defined destructor

Account::Account(Account&& otherAccount) :
        pImpl(std::move(otherAccount.pImpl)) // we grab the other account pImpl and move it to our pImpl
{};

Account& Account::operator=(Account&& otherAccount) {
    pImpl = std::move(otherAccount.pImpl); // we grab the other account pImpl amd move it to our pImpl
    return *this;
}

int Account::Deposit(int amount) {
    return pImpl->Deposit(amount); // we deligate the implementation of the Deposit
}

int Account::Withdraw(int amount) {
    return pImpl->Withdraw(amount); // we deligate the implementation of the Withdrawal
}

