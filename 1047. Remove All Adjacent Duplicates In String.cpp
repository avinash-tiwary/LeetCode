// LeetCode: 1047. Remove All Adjacent Duplicates In String
// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

// =================== BrutForce =============================================
/*
We can itterate over the string with while loop. If found any duplicate then will erase it. After erasing
Don't forget to check previous character.
TC: O(N^2);
SC: O(N)
*/

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length(), i = 0;
        while(i < n-1){
            if(s[i] == s[i+1]){
                s.erase(i, 2);
                if(i > 0) i--;
            }
                
            else i++;
        }
        return s;
    }
};

// ====================== Optimised Approach =================================
/*
Initialize a empty string. Add the charcter in this string if either this string is empty or last char of 
this string is not equal to current itteration char.
If last element of string is empty then we just need to delete it.
TC: O(N)
SC: O(N)
*/
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length(), i = 0;
        string res = "";

        for(char c:s){
            if(!res.empty() && res.back() == c) res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
};
