//
// Created by Svetlana Matculevich on 03/09/2017.
//

//
// Created by Svetlana Matculevich on 03/09/2017.
//
#include<list>
#include<vector>
#include<iostream>

using namespace std;

class ReverseInteger{

public:
    void print_vector(vector<int>& s){
        auto it = begin(s);
        for_each(begin(s), end(s), [&](int elem) {
            auto space = ((++it) != end(s)) ? ", " : "";
            cout << elem << space;
        });
        cout << endl;
    }
    int reverse_int(int num){
        int last_digit;
        int reversed_num = 0;
        while(num != 0){
            last_digit = num % 10;
            reversed_num = reversed_num * 10 + last_digit;
            num /= 10;
        }

        return reversed_num;
    }
};

int main(void){

    int num = 5432;
    ReverseInteger solution;
    cout << solution.reverse_int(num) << endl;
    return 0;

}//
// Created by Svetlana Matculevich on 03/09/2017.
//

