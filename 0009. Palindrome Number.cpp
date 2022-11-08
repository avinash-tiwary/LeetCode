// LeetCode: 9. Palindrome Number
// Link: https://leetcode.com/problems/palindrome-number

// ====================== Simple Approach ================================
/*
First convert integer to string. And then reverse the string and store it in other string variable
then convert it.
TC: O(N)
SC: O(N)
*/

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string revstr(str.rbegin(), str.rend());
        return str == revstr;
    }
};
