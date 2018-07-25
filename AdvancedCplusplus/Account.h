//
// Created by Svetlana Matculevich on 27/06/2017.
//

#pragma one
#include <string>
#include <memory>

class Customer;
// here, were are good with just forward declaration
// since here no one is using methods of AccountImpl
class AccountImpl;

class Account {

private:
    // PImpl idiom: pointer to implementation
    std::unique_ptr<AccountImpl> pImpl;
    // it's not copyable since it uses unique poiter

    // Here there is no other fields stored:balance, log, accountnum,
    // it is all in PImplAccount class

    // So when we are copying copying Account, we are not copying everything

public:
    // constructor
    Account(int bal, Customer* cust);
    ~Account(); // why?

    // no copying rather moving:
    // moving and initializing with moving semantics
    Account(Account&& otherAccount);
    Account& operator=(Account&& otherAccount);

    int Deposit(int amount);
    int Withdraw(int amount);
    std::string BuildDateStringForToday();

};


