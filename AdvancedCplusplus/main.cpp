#include <iostream>
#include "Person.h"
#include "Resource.h"
#include <vector>
#include <map>
#include <set>
#include <list>
#include <array>
#include <algorithm>
#include <numeric>
#include "Stopwatch.h"
#include "Holder.h"

#include "Account1.h"
#include "Account.h"

using namespace std;

// this for the array of T
template <typename T, long unsigned int n>
T sum(std::array<T, n> values){

    int result = 0;
    for (T val : values)
        result += val;
    return result;

}

template <typename T>
void performace_test(T& l, int size){
    l.push_back(0);
    for (int i = 0; i < size; i++)
    {
        int r = (int) rand();
        bool inserted = false;
        for(auto it = begin(l); it != end(l); it++)
        {
            if (*it > r)
            {
                l.insert(it, r);
                inserted = true;
                break;
            }
        }
        if (!inserted)
            l.push_back(r);
    }
    auto it1 = max_element(begin(l), end(l));
    int max_inlist = *it1;
}

template <typename T>
void algorithms_test(T& l){
    // 3 ways to initialize the vector
    //------------------------------------------------------------------------------------------------------------------
    vector<int> v;

    for (int i = 0; i < 5; i++) v.push_back(i);

    for (int i = 0; i < 5; )    v.push_back(i++);

    // how to intialize it with algorithms
    int i = 0;
    // this lambda-function generates the nth element that will be inserted
    // we have capturing i by reference and incrementing
    std::generate_n(std::back_inserter(v), 5, [&]() {return i++;});
    auto print_numbers = [&](vector<int> & v){
        cout << v.size() << " numbers : ";
        for_each(begin(v), end(v), [](auto p){ cout << p << " "; });
        cout << endl;
    };
    print_numbers(v);

    // count how many elements 3 does the vector contains
    //------------------------------------------------------------------------------------------------------------------
    int countTargets2 = 0;
    int const target = 3;
    for (auto it = begin(v); it != end(v); it++)
        if (*it == target) countTargets2++;

    int countTargets = std::count(begin(v), end(v), target);

    int odds = std::count_if(begin(v), end(v), [](auto elem){ return elem % 2 != 0; });
    cout << "number of odds = " << odds << "\n";

    // remove element 3 from the vector
    //------------------------------------------------------------------------------------------------------------------
    auto v4 = v;
    auto endv4 = std::remove_if(begin(v4), end(v4), [](int elem){return (elem == 3);});
    // algorithm is taking range begin(v4), end(v4)
    // and it does remove the element that meets the condition
    // but! it removes the element, shift the good ones <-, but the tail elements are still remainig at the end
    // this is due to the performance reason, simply faster to shift the elements like that
    // rather then performing coping
    // remove_if returns the iterator that point to the new end of the new vector
    // so we need to clean form this iterator till the end of the old vector
    v4.erase(endv4, end(v4)); // in this case we are using a range
    // can also called shorter
    v4.erase(std::remove_if(begin(v4), end(v4), [](int elem){return (elem == 3);}), end(v4));
    cout << "'no 3'";
    print_numbers(v4);
}

template <typename T>
void exercise(int size, string commonname)
{
    T v; // we are making a something
    // types have info inside themselves what it is
    // T::value_type
    typename T::value_type res1("starting entry");
    v.push_back(res1);

    for (int i = 0; i < size; i++)
    {
        int r = (int) rand();
        string s;
        int ss = r % 100; // we have last 2 digits from random and reserve 2 element in the string
        s.reserve(ss);
        std::generate_n(std::back_inserter(s), ss, [ss](){return (char) ('a' + ss/2);}); //we are just generating strings

        typename T::value_type res(s);
        bool inserted=false;

        for(auto it = begin(v); it != end(v); it++){
            if (*it > res)
            {
                v.insert(it, res);
                inserted = true;
                break;
            }
        }
        if (!inserted)  // if at that point there was no insertion performed, we insert it at the end
            v.push_back(res);
    }
    auto it = max_element(begin(v), end(v)); // biggest
    typename T::value_type maxV = *it;
    cout << "max element in " << commonname << ": " << maxV.GetName() << endl;
    it = min_element(begin(v), end(v));
    typename T::value_type minV = *it;
    cout << "min element in " << commonname << ": " << minV.GetName() << endl;

    bool sorted = is_sorted(begin(v), end(v));
    cout << "the " << commonname << " is ";
    if (!sorted)
        cout << " not ";
    cout << "sorted." << endl;

}

#define LIMIT 3
static const int ARRAY_SIZE = 5;
static const int Limit = 7;

enum ComputeType{
    Simple,
    Complex,
    Insane
};
enum NumberType{
    NTReal,
    NTComplex // it is not possible to have two similar enum values
};

void improving_c_classes(){
    // ----------------------------------------------------------
    // animals
    // ----------------------------------------------------------
    // cout is better than printf
    // animals are better than char*
    // vectors are better than array

    // vector<string> animals;
    // string.reserve(ARRAY_SIZE);  // if we know the size

    vector<string> animals = {"zebra", "horse", "cow", "lion", "elephant"}; // uniform initialization

    cout << "Print all the aminals with a loop: ";
    for(auto it=begin(animals); it != end(animals); it++)
        cout << *it << ", ";
    cout << endl;

    cout << "Print all the aminals wiht lambdas: ";
    std::for_each(begin(animals), end(animals), [&](auto elem) { cout << elem << ", "; });
    cout << endl;
    // endl is flushes the buffer and will write the output

    vector<int> numbers;
    //numbers.reserve(ARRAY_SIZE);  // if we know the size, we allocate the memory
    numbers.resize(ARRAY_SIZE);
    // if we know the size, we allocate the memory and initizlize
    // this allocates ARRAY_SIZE zeros
    numbers.push_back(3);
    numbers.push_back(5);

    // better to use then printf() which is very old-style
    cout << "Initialize and print all the nubers with lambdas: \n";
    int i = 0;
    std::for_each(begin(numbers), end(numbers),
                  [&](auto elem) mutable {
                      // we capture i by reference, so we will be changing i
                      cout << ++i << "-th number: " << elem << "\n";
                  }
    );
    cout << endl;

    // algorithms
    int total = accumulate(begin(numbers), end(numbers), 0);
    int total2 = accumulate(begin(numbers), end(numbers), 0, [](auto a, auto b){
                                cout << "a = " << a << "\t b = " << b << endl;
                                // a = a + b / 2
                                return a + b / 2;
                            }
    );
    cout << "total = " << total << "\n";
    cout << "total2 = " << total2 << "\n";

    // templates
    // virtual functions better than function pointers
    // we accumulate animals by +, and we start from "" as an initial
    string allanimals = accumulate(begin(animals), end(animals), string(""), [](auto a, auto b){
        cout << "a = " << a << "\t b = " << b << endl;
        // a = a + b
        return a + b + ", ";
    });
    cout << "All animals: " << allanimals << "\n";

    auto operation_substr = [](auto a, auto b) { return a-b;};
    int total3 = operation_substr(total, numbers[numbers.size()-1]);
    cout << "total3 = " << total3 << "\n";

    // instead of functional-pointer => better to use lambda
    // or virtual function ( + operator is overloaded for string)

}
void pimpl_idiom(){

    // header-files are metadata - description of the project
    // change in header file -> recompilation of the other hunderds of files
    // the way to avoid it is the PImpl ideom

    Account1 a1_1(0, nullptr);
    a1_1.Deposit(50);

    Account1 a1_2(0, nullptr);
    a1_2.Deposit(150);

    // storing implementation of the classes defined on h-file
    // rather in cpp-file helps to later on make changes in cpp
    // without recompiling h-files

    // P.Impl is the concept of splitting pointer definition and its implementation
    // Pointer-Implementation class = compiler firewall
    //
    // Account has one privite pointer to the implemenation class AccountImpl
    //

    // account is not copyable
    Account a_1(0, nullptr);
    a_1.Deposit(50);
    Account a_2(0, nullptr);
    a_2.Deposit(50);

    vector<Account> accounts;
    accounts.push_back(std::move(a_1)); // as soon as we did this move => a_1 became empty, we stole pImpl to Account from it
    accounts.push_back(std::move(a_2));

}
void follow_style_rules(){
    // default parameters
    Holder h1;
    Holder h2("two");
    Holder h3("three", 3);
    h1.Increase();
    h2.Increase(2);

    cout << "h1.Increase() = " << h1.GetNumber() << endl;
    cout << "h1.Increase() = " << h2.GetNumber() << endl;

    // use nullptr
    // if (p)


    int i = 2;
    int *pi = nullptr;

    if (!pi)
        pi = &i;
    if (pi)
    {
        //pi = (4/2) - 1;
        // pi = 0; like NULL
        pi = nullptr;
    }
    i = h1.SomeFunc(2);
    Resource r("a resource");
    i = h1.SomeFunc(&r);     // takes the pointer
    //i = h1.SomeFunc(NULL); // there will be bug since NULL = 0
    i = h1.SomeFunc(nullptr);

    Resource* pr = NULL;
    i = h1.SomeFunc(pr); // this will treat pr as int

    //i = h1.SomeFunc(NULL);

    // no magic numbers
    // -----------------------------------------
    // use
    // enum
    // const
    //
    if (i < 3)
        i++;
    if (i < LIMIT)
        i++;

    // # define LIMIT 4 // they can be redefined, so it is confusing
    if (i < Limit)
        i++;
    if (i > Holder::Limit)
        i++;

    // Limit = 4; // impossible since it is const

    ComputeType ct = Simple;
    if (ct != ComputeType::Insane)
        i = 0;
    if (ct >= ComputeType::Complex)
        i++;

    // const
    // --------------------------------------
    // instruction for the compilier
    // #pragma warning(push)
    // #pragma warning(disable : 40100)
    // #pragma warning(pop)


}
void move_semantics(){

    /*
    cpuStopwatch clock;

    const int size = 5;
    cout << "Running vector and list of " << size << " elements" << endl;
    clock.restart();
    // vector
    exercise< vector<Resource> >(size, "vector");
    cout << "time for vector of Resources: \t " << clock.stop() << endl;
    cout << "--------------------------------------------------------------------\n";
    // vector is copying lots of objects when we are adding stuff
    // but this can be cured with MOVE constructor

    clock.restart();
    // list
    exercise< list<Resource> >(size, "list");
    cout << "time for list of Resources: \t " << clock.stop() << endl;
    cout << "--------------------------------------------------------------------\n";
    */
    // &&
    // -----------------------------------------------------------------------------
    // Foo x        - solid instance of Foo
    // Foo* px      - pointer to a solid instance of Foo
    // Foo& rx      - reference to a solid instance of Foo
    // Foo&& rrx    - rvalue reference to some solid instance of Foo

    // rvalue
    // x - lvalue
    // 3 - rvalue = it is about to die, something we are going to steal from
    //
    // pass by value => OK, as soon as it can be moved
    // returning by value => GREAT candidate for moving
    // write classes that might be movable

    Resource r("local");
    cout << "----------------------------" << endl;
    vector<Resource> resources;
    resources.push_back(r); // here we are passing lvalue
    cout << "----------------------------" << endl;
    resources.push_back(Resource("1st")); // here, passing rvalue
    cout << "----------------------------" << endl;
    for_each(begin(resources), end(resources), [](const Resource& r){ cout << r.GetName() << endl;});
    cout << endl;

    // in the lambda function, it is the best to send parameters by 'const T&'
    // this will use move semantics instead of copying

    // std::move - casts regular value to a rvalue
    // move - is what is used to move ptr in and out of collection
}
void standard_algorithms(){

    cpuStopwatch clock;

    clock.restart();
    cout << "--------------------------------------------------------------------\n";
    list<int> l;
    algorithms_test(l);
    cout << "algorithm time for list: \t" << clock.stop() << endl;
    cout << "--------------------------------------------------------------------\n";

    clock.restart();
    cout << "--------------------------------------------------------------------\n";
    vector<int> v;
    algorithms_test(v);
    cout << "algorithm time for vector: \t" << clock.stop() << endl;
    cout << "--------------------------------------------------------------------\n";

}
void containers(){
    cout << "--------------------------------------------------------------------\n";
    cout << "containers \n";
    cout << "--------------------------------------------------------------------\n";

    // you save time!!! and they are efficient
    // they do the memory management
    // limit cases - resizing
    //
    // RULE of THUMB:
    // - use vector!

    try {
        cout << endl << endl;
        Resource r("local");
        cout << "----------------------------" << endl;
        vector<Resource> resources;
        resources.push_back(r);
        cout << "----------------------------" << endl;
        resources.push_back(Resource("1st"));
        cout << "----------------------------" << endl;
        throw (std::bad_exception());
        // when this exception occures
        // everything what was allocated in vector is getting safely deleted

        resources.push_back(Resource("2st"));
        cout << "----------------------------" << endl;
        resources.push_back(Resource("3st"));
    }
    catch(std::exception& ex ){
        cout << ex.what() << endl;
    }


    // in order to avoid all the copying, we can use the linkedlist
    // but one must measure vector and list  performance
    // vector vs. list demo
    cpuStopwatch clock;

    // for size = 1000: vector is winning
    // for sizes = 10, 100: it's different for each test
    const int size = 10000;
    cout << "Running vector and list of " << size << " elements" << endl;

    clock.restart();
    list<int> l;
    performace_test(l, size);
    cout << "time for list: \t" << clock.stop() << endl;

    clock.restart();
    vector<int> v;
    performace_test(v, size);
    cout << "time for vector: \t" << clock.stop() << endl;

    // Use MAP for the lookup table


    // Containers: array - simplest type

    array<int, 5> numbers = {{1, 2, 3, 4, 5}};
    array<int, 3> numbers2 = {{1, 2, 3}};
    cout << sum(numbers) << endl;
    cout << sum(numbers2) << endl;

    array<float, 3> numbers3 = {{1.0f, 2.4f, 3.6f}};
    cout << sum(numbers3) << endl;

    vector<float> values{1, 2, 3, 4};
    values.push_back(1.5f);
    values.pop_back();

    cout << "there are " << values.size() << " values in ";
    for (float val : values)
        cout << val << "\t ";
    cout << endl;

    try {
        float v = values.at(3);
    }catch (const std::out_of_range& e){
        cout << e.what() << endl;
    }

    // Containers: string
    string speech("to be or not to be, that is the question");
    set<char> letters;

    for (char c : speech)
        if (isalpha(c)) letters.insert(c); // if the character is alpha numeric
    for (char c : letters) // this must be sorted
        cout << c << ", ";
    cout << endl;

    map<char, int> histogram;
    for (char c : speech)
        if (isalpha(c)) histogram[c]++;
    // indexing into a value, histogram[c] i getting the value at character c
    // and is incrementing it
    // in c++: if the value c doesn't it gets initialized into the default value

    // auto here is the pair
    for (auto u : histogram)
        cout << u.first << " - " << u.second << endl;
    // we are getting a sorted map

}
void use_lambdas(){

    cout << "--------------------------------------------------------------------\n";
    cout << "lambda \n";
    cout << "--------------------------------------------------------------------\n";

    // useful concurrency
    // for (int x = 0; x < width; x++) => concurrency::parallel_for(0, width, [](){})

    vector<int>values{1, 2, 3, 4, 5};
    int x = 0;
    int y = 0;

    auto print = [&](){std::cout << "x: " << x << " y: " << y << std::endl;};
    auto print_vector = [&](int elem){std::cout << elem << " ";};

    // capturing everything by reference
    auto print_ = [=](){std::cout << "x: " << x << " y: " << y << std::endl;};
    // capturing everything by value
    // so it will always show
    // x: 0 y: 0
    // x: 0 y: 0
    // x: 0 y: 0
    //
    // therefore for such lambdas (the one that we want to use later)
    // we always have to capture by reference

    //for(int i = 0; i < 5; i++) {v.push_back(i)}

    // mutable is saying that x, y are modifyable
    std::for_each(begin(values), end(values), [=] (int element) mutable {
        x += element;
        y += element;
    });

    //print_();
    print();
    x = y = 0;

    std::for_each(begin(values), end(values), [&, x] (int element) mutable {
        x += element;
        y += element;
    });

    //print_();
    print();
    x = y = 0;

    // difference of capturing by value or by reference
    std::for_each(begin(values), end(values), [&] (int element) mutable {
        x += element;
        y += element;
    });

    //print_();
    print();

    vector<int> valuesDoubled(values.size());
    int factor = 2;

    cout << "original vector: " << endl;
    for_each(begin(values), end(values), print_vector);

    transform(begin(values), end(values), begin(valuesDoubled), [=](int n) {return factor*n;});
    cout << endl << "doubled vector: " << endl;
    for_each(begin(valuesDoubled), end(valuesDoubled), print_vector);
}
void manual_memory_management(){

    cout << "--------------------------------------------------------------------\n";
    cout << "manual memory management \n";
    cout << "--------------------------------------------------------------------\n";

    // RULEs:
    // should not use delete
    // should not use new

    // use local scope, i.e., objects that are instances, NOT pointers
    // use smart pointers for the objects

    // smart programming => using smart pointers:
    // shared_ptr
    // - when it goes out of scope => object of stree store is deleted
    // - make_shared improves performance
    // - object having a shared_ptr as a resource says "i have that, as well as many other observers"
    //
    // unique pointer
    // - less overhead then shared
    // - not copyable => but movable
    // - object having a unique_ptr as a resource says "i have that, i only have it"
    //
    // raw pointer:
    // says I am using it

    // THERE 3 PLACES where ONE NEED POINTER
    // - composition in UML, i.e., member var. which is tied to the class
    //  e.g., account has a transaction list
    // - storage of some object has a pointer to it's observer
    // e.g., list of resources poit to person handling them
    // - shared access to the object on a free store
    // many owners or many observers

    // Ist reason: pointer is solid member of the class
    // - when containing member are copied => the solid members are copied
    // - if there are many resources => use the collection
    // - if the object too large => use unique_ptr

    Person Kate("Kate", "First", 1);
    Kate.AddResourse("Kate Resource");
    Kate.AddResourse("Kate 2nd Resource");

    // Is the resource shared?
    // Or do we make a copy of the resource for each object?
    //
    // Assume that each object must have new resource: deep copy.

    Person Kate2 = Kate; // this will complain since unique_ptr
    Kate = Kate2;        // we didn't write a copy of the resource function
    string s1 = Kate.GetResourceName();
}

int main() {
    // manual_memory_management();
    // use_lambdas();
    // containers();
    // standard_algorithms();
    // move_semantics();
    // follow_style_rules();
    // pimpl_idiom();
    // improving_c_classes();
    return 0;
}