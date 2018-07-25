//
// Created by Svetlana Matculevich on 03/09/2017.
//

//
// Created by Svetlana Matculevich on 03/09/2017.
//
#include<list>
#include<map>
#include<vector>
#include<iostream>

using namespace std;

class ZigZagConversion{

    vector<int> v1, v2;

public:

    void print_zigzag(string& str, int len_num, map<pair<int, int>, int> mult, int last_i_pos){
        int k = 0;
        int i_len = 0;
        for (int j = 0; j < len_num; j++)
        {
            for (int i = 0; i <= last_i_pos; i++) {
                pair<int, int> ind = make_pair(j, i);
                auto it = mult.find(ind);
                if (it != end(mult))
                    cout << str[(*it).second] << " ";
                else
                    cout << "  ";
            }
            cout << endl;
        }
    }
    int zigzag_conversion(string& str, int len_num, map<pair<int, int>, int>& mult){
        int n = str.size();

        int k = 0;
        int i = 0, j = 0;
        int incr_j = 0;
        int incr_i = 1; // 2nd shape of a zigzag, no update in the loop
        //int incr_i = 0; // 1st shape of a zigzag
        while (k < str.size()){
            if (j == 0) {
                //incr_i = 0; // 1st shape of a zigzag
                incr_j = 1;
            }
            if (j % (len_num - 1) == 0 && j != 0){
                //incr_i = 1; // 1st shape of a zigzag
                incr_j = -1;
            }
            pair<int, int>ind = make_pair(j, i);
            mult[ind] = k;
            i +=incr_i;
            j +=incr_j;
            k++;
            cout << k << "-th: (" << j << ", "<< i << ")" << endl;
        }
        return i;
    }
    void output_empty_string(string& empty_str, int num_empty_chars){
        empty_str.assign(num_empty_chars, ' ');
        //cout << string {"hello"} << end;
        cout << empty_str;
        empty_str.clear();
    }
    // Function to print given string in zig-zag form in k rows
    void printZigZag(string str, int k)
    {
        // base case
        if (k == 1)
        {
            cout << str;
            return;
        }
        string empty_str;

        // print first row
        for (int i = 0; i < str.length(); i += (k-1)*2) {
            cout << str[i] << " ";
            output_empty_string(empty_str, 2*((k-1) + (k-2)));
        }
        cout << endl;
        // print middle rows
        for (int j = 1; j < k - 1; j++)
        {
            bool down = true;
            for (int i = j; i < str.length();)
            {
                if (down) { // going down
                    output_empty_string(empty_str, j*2);
                    cout << str[i] << " ";
                    // 1*2 elements are added to add the shift for the bottom and top elements
                    output_empty_string(empty_str, (k-1-j)*2 - 2);

                    i += (k-j-1)*2;
                }
                else{ // going up
                    output_empty_string(empty_str, (k-1-j)*2);
                    cout << str[i] << " ";
                    // 1*2 elements are added to add the shift for the bottom and top elements
                    output_empty_string(empty_str, j*2 - 2);
                    i += 2*j;
                }
                down = !down; // switch direction
            }
            cout << endl;
        }
        // print last row
        for (int i = k - 1; i < str.length(); i += (k-1)*2) {
            output_empty_string(empty_str, 2*(k-1));
            cout << str[i] << " ";
            output_empty_string(empty_str, 2*(k-2));
        }
        cout << endl;
    }
};

int main(void){

    string str{"THISPROBLEMISAWESOME"};
    ZigZagConversion zigzag;
    int num_str = 5;

    map<pair<int, int>, int> mult;
    cout << "solution with a map:" << endl;
    int last_i_pos = zigzag.zigzag_conversion(str, num_str, mult);
    zigzag.print_zigzag(str, num_str, mult, last_i_pos);

    cout << "alternative solution:" << endl;
    zigzag.printZigZag(str, num_str);
}