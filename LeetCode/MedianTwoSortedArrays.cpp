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

class MedianTowSortedArrays{

    vector<int> v1, v2;

public:
    MedianTowSortedArrays(vector<int> _num1, vector<int> _num2): v1(_num1), v2(_num2){}

    void print_vector(vector<int>& s){
        auto it = begin(s);
        for_each(begin(s), end(s), [&](int elem) {
            auto space = ((++it) != end(s)) ? ", " : "";
            cout << elem << space;
        });
        cout << endl;
    }
    double find_median(){
        int new_size = v1.size() + v2.size();
        vector<int> merged;

        merge(begin(v1), end(v1), begin(v2), end(v2), back_inserter(merged));
        print_vector(merged);
        return (new_size % 2) ?
                  merged[new_size / 2] :
                 (merged[new_size / 2 - 1] + merged[new_size / 2]) / 2.0 ;
    }
};

int main(void){

    vector<int> v1{1, 2, 3};
    vector<int> v2{0, 2, 4, 5, 6};
    MedianTowSortedArrays median(v1, v2);
    cout << median.find_median() << endl;

}