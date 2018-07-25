//
// Created by Svetlana Matculevich on 03/09/2017.
//

#include<list>
#include<map>
#include<set>
#include<vector>
#include<iostream>

using namespace std;

class SubstringWithoutRepetiotion{

    string str;

public:
    SubstringWithoutRepetiotion(string _str): str(_str){}

    void print_set(set<char>& s){
        auto it = begin(s);
        for_each(begin(s), end(s), [&](char elem) {
            auto space = ((++it) != end(s)) ? ", " : "";
            string str(1, elem);
            cout << str << space;
        });
        cout << endl;
    }
    void print_map(map<char,int> s){
        auto it = begin(s);
        for_each(begin(s), end(s), [&](pair<char, int> elem) {
            auto space = ((++it) != end(s)) ? ", " : "";
            string str(1, elem.first);
            str += to_string(elem.second);
            cout << str << space;
        });
        cout << endl;
    }
    int length_of_longest_substr(){
        int length = 0;
        set<char> charachters;
        // (list_indx, j]
        // sliding window in a string, wher  we are looking for substring
        for(int i = 0, j = 0; j < str.size();){
            cout << "----------------------------------------------------" << endl;
            cout << "[list_indx, j) = [" << i << ", " << j << ")"<< endl;
            auto it = charachters.find(str[j]);
            if (it == charachters.end()){
                charachters.insert(str[j]);
                length = max(length, j + 1 - i);
                j++;
            }
            else {
                charachters.erase(str[i]);
                i++;
            }
            print_set(charachters);
            cout << "----------------------------------------------------" << endl;
        }
        return length;
    }
    int length_of_longest_substr_with_map(){
        int length = 0;
        map<char, int> charachters;
        // (list_indx, j]
        // sliding window in a string, wher  we are looking for substring
        for(int i = 0, j = 0; j < str.size(); j++){
            cout << "----------------------------------------------------" << endl;
            cout << "[list_indx, j) = [" << i << ", " << j << ")"<< endl;
            auto it = charachters.find(str[j]);
            if (it != charachters.end()) {
                string str(1, (*it).first);
                cout << "found elem = [" << str + "," + to_string((*it).second) << "]"<< endl;
                i = max(i, (*it).second);
            }
            length = max(length, j - i);
            charachters[str[j]] = j; // this is replacing the existing element in the table

            print_map(charachters);
            cout << "----------------------------------------------------" << endl;
        }
        return length;
    }
};

int main(void){
    SubstringWithoutRepetiotion str("abcabcbb");
    //SubstringWithoutRepetiotion str("bbbbbbbb");
    //SubstringWithoutRepetiotion str("pwwkew");
    //cout << str.length_of_longest_substr() << endl;
    cout << str.length_of_longest_substr_with_map() << endl;
    return 0;
}