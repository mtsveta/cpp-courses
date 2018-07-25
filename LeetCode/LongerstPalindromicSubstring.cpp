//
// Created by Svetlana Matculevich on 03/09/2017.
//
#include<iostream>

using namespace std;

class Solution {

public:
    // A utility function to print a substring str[low..high]
    void expandAroundCenter(int & low, int & high, string str, int & start, int & maxLength){
        while (low >= 0 && high < str.size() && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    int longestPalindrome(string str) {

        int maxLength = 1;  // The result (length of LPS)
        int start = 0;
        int low, high;

        // One by one consider every character as center point of
        // even and length palindromes
        for (int i = 1; i < str.size(); i++)
        {
            // Find the longest even length palindrome with center points
            // as list_indx-1 and list_indx.
            low = i - 1;
            high = i;
            expandAroundCenter(low, high, str, start, maxLength);

            // Find the longest odd length palindrome with center
            // point as list_indx
            low = i - 1;
            high = i + 1;
            expandAroundCenter(low, high, str, start, maxLength);
        }

        cout << "Longest palindrome substring is: "
             << string(str, start, maxLength) << endl;
             // << str.substr(start, maxLength) << endl; two ways to define this substring

        return maxLength;
    }
};

int main(){

    string str = "forgeeksskeegfor";

    Solution solution;
    int maxLength = solution.longestPalindrome(str);
    cout << "Max length of LPS: " << maxLength << endl;
    return 0;
}

//
// Created by Svetlana Matculevich on 04/09/2017.
//

