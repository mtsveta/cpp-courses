//
// Created by Svetlana Kyas on 11.05.19.
//
#include <iostream>     // for std::cout, std::endl
#include <memory>       // to std::unique_prt, std::make_unique
#include <chrono>       // for std::chrono
#include <vector>       // for std::vector
#include <fstream>      // for std::fstream
#include <algorithm>    // for std::find, std::for_each,
#include <type_traits>  // for std::is_integral
#include <string>       // for std::string
#include <map>          // for std::map

auto syntactic_sugar() -> void
{
    // digits separators
    long x = 10'000'000;

    // binary values with a prefix '0b' or '0B'
    auto d = 0b01000111;
    auto word = 0b01000111'01000011;

    /*
    // automatic return type deduction
    auto AreaOfSquare(double side){

        // std::map<std:string, SomeLongValueType> result;
        // ...
        // return result;

        return side*side;
    }
    */
    // gcc –version
}

// ************************************************************************** //
// ************************************************************************** //

[[deprecated("DoSomething() routine will be deprecated in the next version. Use DoSomethingBetter() instead.")]]
auto DoSomething() -> void {
    std::cout << "DoSomething is envoked." << std::endl;
}

auto DoSomethingBetter() -> void {
    std::cout << "DoSomethingBetter is envoked." << std::endl;
}

// constexpr is forcing the func to be evaluated at the compile time
constexpr int Fibonacci(int n)
{
    switch (n){
        case 0: return 0;
        case 1: return 1;
        default:
            return Fibonacci(n-1) + Fibonacci(n-2);
    }
}

// function template
template <typename T>
auto Max(T a, T b) -> T
{
    if (a > b)
        return a;
    else
        return b;
}
// variable template
// generic type
template <typename T>
constexpr T maxValue = T(1000);

// template specialisation: specialisation of the generic type to double
template <>
constexpr double maxValue<double> = 2000;

template <>
constexpr char maxValue<char> = 'Z';

auto improvements_to_cpp11() -> void
{
    // relaxed constexp functions
    // -------------------------------------------------------------------------
    // constexpr double DoSomething(){
        // ...
    // };
    // code of these functions are evaluated and executed at the compile-time
    //
    /*
    std::cout << "index ? ";
    int i{};
    std::cin >> i;
    std::cout << "F(" << i << ") = " << Fibonacci(i) << '\n';
    */

    // static assert is used instead of normal assert
    // it is verified at the compile time
    static_assert(Fibonacci(10)==55, "Unexpected Fibonacci number");
    // static_assert(Fibonacci(10)==45, "Test 'wrong' assert");

    // variable template
    // -------------------------------------------------------------------------
    double a(9.0);
    double b(3.4);

    std::cout << "Max(a, b) = " << Max(a, b) << std::endl;

    // template <typename T>
    // constexpr T pi = T(3.141592);

    // if pi will be called with pi<double> -> the value of pi will be rounded to the pi with a double precision
    // if pi<float> ->

    // specialise the variable templates
    std::cout << "maxValue<int>    = " << maxValue<int> << std::endl;
    std::cout << "maxValue<double> = " << maxValue<double> << std::endl;
    std::cout << "maxValue<char>   = " << maxValue<char> << std::endl;

    // the [[deprecated]] attribute
    // DoSomething();

}

// ************************************************************************** //
// ************************************************************************** //

class X{
public:
    X(){std::cout << "X constructor\n";}
    ~X(){std::cout << "X destructor\n";}
    auto sayHi() -> void {std::cout << "X says hi! :) \n";}

private:
    int m1{};
    double m2{3.14};
};
// examples of using unique pointer
class Image{
    int height;
    int width;
    std::unique_ptr<int []> mPixels;
};

/*
class Factory{
    auto makeObject() -> std::unique_ptr<SomeObject>
};
*/

auto print(std::chrono::milliseconds ms) -> void {
    std::cout << ms.count() << " ms \n";
}
auto standard_library_improvement() -> void
{
    // raw pointers
    // -------------------------------------------------------------------------
    // stack
    // - fast allocating the memory
    // + stack is very limited resource
    int n{64};
    double d{3.54};
    bool success{true};

    // heap
    // + is used when the large chunks of memory are needed
    // - very slow
    double *p = new double[10000]; // allocating 1000000 doubles

    std::unique_ptr<double> p_smart =  std::make_unique<double>(d);

    // unique pointers
    // -------------------------------------------------------------------------
    // create a unique_ptr to an array of 1 million doubles
    // std::unique_ptr name = std::make_unique<type of smart pointer>(number of variables);
    std::unique_ptr<double[]> p_doubles = std::make_unique<double[]>(1'000'000);

    // no new and delete!
    //
    /*
    X* pX = new X{};
    pX->sayHi();
    delete pX;
    */

    auto pX_smart = std::make_unique<X>();
    pX_smart->sayHi();
    // as soon as the pointer goes out of score
    // destroctor is envoked

    // literals and chrono library
    // -------------------------------------------------------------------------

    // sleep(20ms);
    using namespace std::chrono;
    seconds s{};                    // 0-initialized
    seconds dt{10};
    auto t0 = 0s;                   // 0s (C++14!)
    auto t1 = 10s;                  // 10s (C++14!)

    // auto = pointer (const char*)
    auto str = "Connie";
    // auto = std::string
    // auto str2 = 'Maggie's; ???
    // auto = std::chrono::seconds

    // all the convertions are done at the compile time
    auto x = 2s;                            // auto = std::chrono::seconds
    std::cout << "x = 2s : "; print(x);     // chrono library automatically converts

    auto y = 150ms;
    std::cout << "y = 150ms : "; print(y);

    auto z = x + y;
    std::cout << "z = y + x : "; print(z);

    constexpr auto timeLimit = 3s;
    std::cout << "\nTime limit is "; print(timeLimit);

    if (z < timeLimit) std::cout << "All is right! \n";


    // tuples and fetching elements by type
    // -------------------------------------------------------------------------
    // tuples of objects of different type
    // std::pair
    // std::tuple

    std::tuple<std::string, std::string, int, char> student("Svet", "Weber", 2, '5');
    double gpa = std::get<2>(student);
    char grade = std::get<char>(student);

}

// ************************************************************************** //
// ************************************************************************** //

template <typename T>
auto print(const std::vector<T> & collection) -> void{
    std::for_each(std::begin(collection), std::end(collection),
                  [](const T & e){ std::cout << e << std::endl; });
    // Simpler
    // for (const auto & s)    std::cout << e << std::endl;
}

auto better_lambda() -> void
{
    std::vector<std::string> names{"Mike", "Elena", "John", "Philipp", "Svetlana"};
    std::for_each(std::begin(names), std::end(names),
                  [](const std::string & e){ std::cout << e << "\t"; });
    std::cout << std::endl;

    std::sort(std::begin(names), std::end(names),
              [](const std::string & a, const std::string & b){
                return a.length() < b.length(); });
    std::for_each(std::begin(names), std::end(names), [](const std::string & e){
        std::cout << e << "\t";
    });
    std::cout << std::endl;


    // Cpp 14: Generic (polymorphic) lambda
    //
    //
    std::ifstream file{"data.txt"};
    std::vector<std::string> lines{};
    std::string line;

    if (file.is_open()){
        while (std::getline(file, line)) {
            lines.emplace_back(line);
        }
    }
    print(lines);
    std::sort(std::begin(lines), std::end(lines),
              [](const auto & a, const auto & b){
                  return a.length() < b.length(); });
    print(lines);

    // Init captures in lambda
    //
    // [] is a capture list
    int x{2};
    double y{2.32};
    int value{};
    // by value
    // by reference
    auto example = [x, y, value = 64](auto a, auto b){
        std::cout << a << std::endl;
    };

    //
    std::unique_ptr<int> p1;
    auto p2 = std::make_unique<int>(64);

    auto func = [u = std::move(p2)](){
        std::cout << *u << std::endl;
    };
    func();
}

// ************************************************************************** //
// ************************************************************************** //


template <typename T>
auto length(const T& value) -> int
{
    // without constexpr it won't compile
    if constexpr (std::is_integral<T>::value){
        return value;
    }
    else{
        return value.length();
    }
}

auto practical_improovements_cpp17() -> void{
    // embedded namespaces
    /*
    namespace PluralsightEngine {
        namespace Graphics{
            namespace Rendering{

            }
        }

    }
    */
    // Cpp 17
    /*
    namespace PluralsightEngine::Graphics::Rendering{
        class OpenGLRender{

        };
    }
    */
    // Type declaration in if statement
    std::vector<std::string> names{"Mike", "Elena", "John", "Philipp", "Svetlana"};
    if (const auto it = std::find(names.begin(), names.end(), "Helena"); it != names.end() )
        *it = "**";
    else
        std::cout << "Name is not found!" << std::endl;

    /*
    switch (auto it = std::find(names.begin(), names.end(), "Helena"); it != names.end() ) {
        case "Hello":
        case "World":
        default:
    }
     */

    // Constexpr if vs. ordinary if
    if constexpr (1 == 0){

    } else {

    }
    // useful in templated code
    /*
    template <typename T>
    auto DoSomething(const T& value)
    {
        if constexpr (T is an int){
            // Do one thing
        }
        else if (T is a string){
            // Do something else
        }
    }
     // The conditions that are not passing are not even compiled
    */
    std::string s{"Connie"};
    int i{10};

    std::cout << "s = " <<  length(s) << std::endl;
    std::cout << "i = " <<  length(i) << std::endl;

    // Structure bindings
    std::map<std::string, std::string> dict{
        {"case", "home"},
        {"gatto", "cat"},
        {"pasta", "pasta"}
    };
    auto result = dict.insert({"sedia", "chair"});
    // auto std::pair with iterator and boolean
    // if element exists - iterator pointing to new element + true
    // is element does not exist - iterator to the end of the map + fause
    auto [position, success] = dict.insert({"mamma", "mother"});

    if (success) {
        std::cout << "Insersion is OK" << std::endl;
    }
    for (const auto & [it, eng] : dict)
        std::cout << "it: " << it << "\teng: " << eng << std::endl;
}

int main(){


    // syntactic_sugar();
    // improvements_to_cpp11();
    // standard_library_improvement();
    // better_lambda();
    practical_improovements_cpp17();


    return 0;
}