//
// Created by Svetlana Matculevich on 31/08/2017.
//
#include "Account.h" // we could create "Account.h" and "Transaction.h"

using namespace std;

// default constructor
Account::Account(const double balance):balance(balance){
    this->transaction_number = 0;
}
void Account::increaseTransactionNumber(){
   this->transaction_number += 1;
}


void Account::addTransaction(const double & amount, const string& type)
{
    increaseTransactionNumber();
    transactions.emplace_back(Transaction(amount, string{type + ", "+ to_string(transaction_number)}));
    //transactions.emplace_back(transaction);
}

bool Account::deposit(const double money)
{
    if (money >= 0)
    {
        addTransaction(money, "deposit");
        this->balance += money;
        addTransaction(1, "service charge");
        this->balance += 1;
        return true;
    }
    else { return false; }
}
bool Account::withdraw(const double money)
{
    if (this->balance - limit < money) {
        cout << "sorry! the balance is not enough for such a transaction" << endl;
        return false;
    }
    else {
        addTransaction(money, "withdraw");
        this->balance -= money;
        addTransaction(1, "service charge");
        this->balance -= 1;

        return true;
    }
}
vector<string> Account::report() const
{
    vector<string> report;
    report.emplace_back("Balance is " + to_string(balance));
    report.emplace_back("Transactions:");
    for (auto t : transactions)
        report.emplace_back(t.reportAboutTransation());
    return report;
}

void Account::reportAccountTransaction() const
{
    for (Transaction elem : this->getTransactions())
        elem.reportAboutTransation();
}