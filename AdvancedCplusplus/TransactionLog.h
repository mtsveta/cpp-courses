//
// Created by Svetlana Matculevich on 27/06/2017.
//

#ifndef DEMOS_TRANSACTIONLOG_H
#define DEMOS_TRANSACTIONLOG_H
#pragma one
#include <string>

class Account1;
class Account2;
class Account3;
class AccountImpl;

class TransactionLog {

private:
    int accnum;
public:
    TransactionLog(int an) : accnum(an){};
    void AddDeposit(std::string date, int amount){}
    void AddWithdrawal(std::string date, int amount){}
};


#endif //DEMOS_TRANSACTIONLOG_H
