//
// Created by Svetlana Matculevich on 03/09/2017.
//
#include<list>
#include<vector>
#include<iostream>

using namespace std;

class AddTwoNumbers{

    list<int> num1, num2;

public:
    AddTwoNumbers(list<int> _num1, list<int> _num2): num1(_num1), num2(_num2){}

    void add_two_numbers(list<int>& sum){
        // assume by default that second number is shorter
        auto it_short = rbegin(num2),
                it_short_end = rend(num2),
                it_rbegin = rbegin(num1),
                it_rend = rend(num1);

        if (num1.size() < num2.size()){
            it_short = rbegin(num1);
            it_short_end = rend(num1);
            it_rbegin = rbegin(num2);
            it_rend   = rend(num2);
        }
        int first_digit = 0;
        int digit_sum = 0;
        int rest = 0;
        for (auto it = it_rbegin; it != it_rend; it++, it_short++){
            digit_sum = (it_short != it_short_end) ?
                        (*it) + *(it_short) + first_digit :
                        (*it) + first_digit;

            rest = digit_sum % 10;
            first_digit = digit_sum / 10;
            sum.emplace_front(rest);
        }
    }
};

int main(void){

    list<int> num1{1, 2, 4, 3};
    list<int> num2{5, 6, 4};
    list<int> sum;

    AddTwoNumbers addTwoNumbers(num1, num2);
    addTwoNumbers.add_two_numbers(sum);

    auto print_list = [&](list<int>& l) {
        auto it = begin(l);
        for_each(begin(l), end(l), [&](int elem) {
            auto space = ((++it) != end(l)) ? " -> " : "";
            cout << elem << space;
        });
    };

    cout << "(" ;
    print_list(num1);
    cout << ") + (" ;
    print_list(num2);
    cout << ") = " ;
    print_list(sum);




}