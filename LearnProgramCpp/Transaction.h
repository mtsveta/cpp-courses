// NO NAMESPACES in HEADER FILES
#include <string>

class Transaction{
    std::string _data = "02.01.1989";
    double amount;
    std::string type;

public:
    Transaction(const double & amount, const std::string& type);
    std::string reportAboutTransation();
    void doubleTransaction(){ amount *= 2;}
};
