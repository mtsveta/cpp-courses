#include <iostream>
#include "Transaction.h"

using namespace std;

Transaction::Transaction(const double & amount, const string & type) :
        amount(amount), type(type){
}
string Transaction::reportAboutTransation(){

    return "transaction: amount = " + to_string(amount) +
            " (" + type + ")";
    //cout << "transaction: amount = " << amount << "\t"
    //     << "type   = "           << type << endl;
}
