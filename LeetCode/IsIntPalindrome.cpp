//
// Created by Svetlana Matculevich on 04/09/2017.
//

//
// Created by Svetlana Matculevich on 03/09/2017.
//
#include<iostream>

using namespace std;

class Solution {

public:

    bool isPalindrome(int num) {

        // edge cases:
        // - negative numbers are not palindrome
        // - numbers with 0 at the end are not palindrome
        if (num < 0 || (num % 10 == 0 && num != 0))
            return false;
        int reversed_num = 0;
         // One by one consider every character as center point of
        // even and length palindromes
        while (reversed_num < num)
            reversed_num = reversed_num * 10 + num % 10;

        // first condition for even-digit numbers: 1221
        // second condition for odd-digit numbers: 12321
        return (reversed_num == num) || (num == reversed_num / 10);
    }
};

int main(){

    // time complexity: O(log_10 n)
    // space complexity: 0(1)

    int num = 1221;
    Solution solution;
    bool isPalindrome = solution.isPalindrome(num);
    cout <<  isPalindrome << endl;

    return 0;
}

//
// Created by Svetlana Matculevich on 04/09/2017.
//

