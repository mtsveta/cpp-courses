#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort and count

#include "Functions.h"
#include "Account.h"

// when using other libraries, should be used with caution
using namespace std;

template <typename T>
auto print(const vector<T> collection){
    for (T elem : collection)
        cout << elem << " ";
    cout << endl;
}

auto stream_locals_flowofcontrol() -> void
{
    // How source code becomes executable:
    // --------------------------------------------------------------------
    // - compiling: source code (of a several files) -> object files (obj)
    // - object files linked together -> executable file (exe) or library file (lib, bin)

    // C++ is
    // --------------------------------------------------------------------
    // - case sensitive
    // - {}, ()
    // ; - end of line
    // not all the application are starting with main()

    // Build gives the information about:
    // - compiler
    // - getting it linked

    // For compiling:
    // --------------------------------------------------------------------
    //$ clang main.cpp  or
    //$ gcc --std=c++14 main.cpp
    //$ g++ --std=c++14 main.cpp
    //
    // for running:
    //./a.out

    // $ make
    // $ ./LearnProgramCpp
    // Errors:
    // --------------------------------------------------------------------
    // 1) forgotten ';' COMPILER ERRORS
    // main.cpp:53:13: error: expected ';' after return statement
    //
    // 2) main => man   LINKER ERRORS
    // Undefined symbols for architecture x86_64: "_main", referenced from:
    // implicit entry/start for main executable
    // ld: symbol(s) not found for architecture x86_64
    // clang: error: linker command failed with exit code 1 (use -v to see invocation)

    // STL: the standard library
    // --------------------------------------------------------------------
    // I) stream / io
    // << send something to a stream, 'insertion'
    // >> read something form a stream, 'extraction operator'
    //
    // #include<iostream>
    // we are sending something to cout
    cout << 2 + 2 << endl << "Hello" << endl << 3 * 5.6 << endl;

    // #include
    // - new library

    // namespace, std::
    // we can have the cout function in my_namespace namespace
    // prevents conflicts

    // Local variables (initialization):
    // --------------------------------------------------------------------
    // typed, must be initialized
    int i; // warning: initialize the int variable

    // fractional part will be lost
    int j = static_cast<int>(7.2); // warning: implicit conversion from 'double' to 'int' changes value from 7.2 to 7

    cout << i << endl << j << endl;

    // auto request from the compiler to figure out the type
    auto f = 4.5;
    cout << f << endl;
    f = 9.0 / 5; // to get a float variable one of the variable must be float
    cout << f << endl;

    // i = "hello";        // error: invalid conversion from 'const char*' to 'int' [-fpermissive]
    // f = 1.0 / "hello";  // error: invalid operands of types 'double' and 'const char [6]' to binary 'operator/'

    // Flow of control
    // --------------------------------------------------------------------

    int answer, correct_number = 7;
    bool notguessed = true;

    while (notguessed) {
        cout << "Guess the number:" << endl;
        cin >> answer;
        cout << "You have entered " << answer << endl;
        if (answer < 7) cout << "You have guessed too low ... " << endl;
        else if (answer > 7) cout << "You have guessed too high ..." << endl;
        else {
            notguessed = false;
            cout << "You have guessed correct!" << endl;
        }
    }
}

auto functions_headers() -> void
{
    // Overloading
    // --------------------------------------------------------------------
    // function with the same name but different input parameters
    // better to overload on the number of arguments

    // main arguments
    // int main(int argc, char* argv[]){
    // return 0;
    //}
    // argc - number of arguments
    // argv[] - collection
    // char* - string type

    // Errors:
    // --------------------------------------------------------------------
    // 1) COMPILER ERRORS
    // start with C***:
    // if we have forgotten to declare a function:
    // double add(double a, double b);
    // error: use of undeclared identifier 'add'
    // double sum = add(5, 6);
    //
    // 2) LINKER ERRORS
    // start with LK
    // if we have forgotten to define function:
    // add(double, double)
    // linker error: Undefined symbols for architecture x86_64:
    // "add(double, double)", referenced from:
    //

    cout << add(3, 5) << endl;
    // --------------------------------------------------------------------
    // casting
    // --------------------------------------------------------------------
    int int_from_double = static_cast<int>(4.9);

    // dynamic_cast<>
    // const_cast<>

    // --------------------------------------------------------------------
    // const value
    // --------------------------------------------------------------------

    const int amount = 90;
    int i2 = (int) 4.9;
    int i3 = static_cast<int>(4.9);

    // const function = the function that is not changing the value of anything

    // #define Pi 3.14 => must be replaced
    // const double Pi = 3.14;

    // #define SQR(x) (x*x) => must be replaced by the function
    // SQR(1+1) => SQR(1+1*1+1) => 3
}

auto strings_collections() -> void
{
    // Strings
    // --------------------------------------------------------------------
    // char* => strings
    // char* '\0'

    string name;
    cout << "who are you? ";
    cin >> name;
    cout << endl;
    string greeting = "hello, " + name;
    cout << greeting << endl;

    // get length
    int length = greeting.length();
    cout << "greeting is " << length << " character long!" << endl;

    // find character
    auto space = greeting.find(' '); // will return the iterator pointer
    string begining = greeting.substr(space + 1);
    cout << "substring is " << begining << endl;

    if (begining == name)
        cout << "we found the name" << endl;

    string name1, name2;
    cout << "enter the first word: ";
    cin >> name1;
    cout << "enter the secont word: ";
    cin >> name2;

    if (name1.length() < name2.length())
        cout << "second name is longer" << endl;
    else if (name1.length() > name2.length())
        cout << "first name is longer" << endl;
    else
        cout << "words are the same length!" << endl;

    // strcpy
    // strcat
    //
    // typedef int BOOL
    //
    // why to use:
    // - for portability
    // - for expressivity to show that sometimes int is to represent the SIZE
    //   another time to represent the POSITION

    // Collections / vectors
    // -----------------------------------------------------------------
    // vector is the tmeplate since it works with any type
    vector<int> vi = vector<int>{1, 2, 3, 4, 5};
    vector<string> vs = vector<string>{"123", "234", "345"};
    print(vs);

    cout << "enter three words " << endl;

    //{ scope of 'i'
    for (auto i = 0; i < 3; i++) {
        string s;
        cin >> s;
        vs.emplace_back(s);
    }
    //}
    cout << endl;

    sort(begin(vi), end(vi));
    cout << "now the numbers are: " << endl; print(vi);
    sort(begin(vs), end(vs));
    cout << "now the strings are: " << endl; print(vs);

    // count the amount of number 3
    auto num_three = count(begin(vi), end(vi), 3);
    cout << "number of three " << num_three << endl;
    // count the amount of letter 't'
    auto letter_t = count(begin(vs[1]), end(vs[1]), 3);
    cout << "number of letter t " << letter_t << endl;

    // synonyms
    typedef std::vector<int> VectorOfInt;
    VectorOfInt numbers{1, 2, 3};

    typedef std::vector<double> VectorOfDouble;
    VectorOfDouble morenumbers{1.3, 2.5, 3.7};
}


void changeTransactions(vector<Transaction>& t){
    for (auto elem : t)
        elem.doubleTransaction();
}
void tryToChangeTransaction(Transaction t){
    cout << t.reportAboutTransation() << endl;
    t.doubleTransaction();
    cout << t.reportAboutTransation() << endl;
}
void changeTransaction(Transaction& t){
    cout << t.reportAboutTransation() << endl;
    t.doubleTransaction();
    cout << t.reportAboutTransation() << endl;
}

auto classes() -> void
{
    Account a1(30.0);
    const double amount = 90.0;
    a1.deposit(90.0);
    cout << "after depositing 90$" << endl;
    a1.report();
    a1.reportAccountTransaction();

    // amount = 50.0; // this is impossible because amount is const
    a1.withdraw(50.0);
    if (a1.withdraw(100.0)){
        cout << "transaction was successful!" << endl;
    }
    cout << "after withdrawal 50$ and 100$" << endl;
    for (auto elem : a1.report())
        cout << elem << endl;
    //a1.reportAccountTransaction();


    cout << "after depositing 100$" << endl;
    a1.deposit(100.00);
    for (auto elem : a1.report())
        cout << elem << endl;

    cout << "------------------------------------------" << endl;
    changeTransaction(*(a1.getTransactions().begin()));
    cout << "------------------------------------------" << endl;
    //a1.reportAccountTransaction();

    cout << "------------------------------------------" << endl;
    tryToChangeTransaction(*(a1.getTransactions().begin()));
    vector<Transaction> vect = a1.getTransactions();
    changeTransactions(vect);
    for (auto elem : a1.report())
        cout << elem << endl;

    // INLINE functions (normally short)
    // --------------------------------------------------
    // when class implementation is in .h and .cpp files
    // inline functions are those, which are defined in .h file


    // ENCAPSULATION:
    // - having protected members in the private => no one from outside can change it
    // - function that are services => must be available => public
    //
    // since C++ won't initialize things for us:
    // we have CONSTRUCTORS

    // :: scope resolution

    // the semicolon shouldn't be forgotten

    // command line compiling
    // g++ -std=c++14 Classes.cpp Account.cpp Transaction.cpp


    // MAKE file
    // --------------------------------------------------
    //
    // we can either make cmake file with
    // all: g++ -std=c++14 Classes.cpp Account.cpp Transaction.cpp -o Classes
    //
    // or
    //
    // all: simple
    // simple: Account.o Transaction.o Classes.o
    //         g++ Account.o Transaction.o Classes.o -o ClassesDemo
    //
    // Account.o: Account.cpp Account.h Transaction.h
    //            g++ -c Account.cpp
    //
    // Transaction.o Transaction.cpp Transaction.h
    //            g++ -c Transaction.cpp
    //
    // Classes.o Classes.cpp Account.h
    //            g++ -c Classes.cpp


    // function() const
    // function that doesn't change the value of anything
    //
    // STL
}
int main() {

    // stream_locals_flowofcontrol();
    // functions_headers();
    // strings_collections();
    classes();
}