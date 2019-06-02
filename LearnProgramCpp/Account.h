//
// Created by Svetlana Matculevich on 31/08/2017.
//
#include <vector>
#include <string>
#include <iostream>

#include "Transaction.h"

// never use NAMESPACES in HEADERFILES!

class Account {
    // balance
    std::vector<Transaction> transactions;
    double balance;
    int transaction_number;
    const double limit = -60;

public:

    Account(const double balance = 0.0);
    void increaseTransactionNumber();

    bool deposit(const double money);
    bool withdraw(const double money);
    std::vector<std::string> report() const;

    // Manipulations with transaction
    std::vector<Transaction> getTransactions() const{ return this->transactions; }
    void reportAccountTransaction() const;
    void addTransaction(const double & amount, const std::string& type);

    // as soon as  for the short functions we are defining them here
    // they become inline functions!
    double getBalance() const {return balance;}

};



