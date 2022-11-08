// LeetCode: 13. Roman to Integer
// Link: https://leetcode.com/problems/roman-to-integer
// =========================== Optimal Approach ======================
/*
Create a map and store the roman to interger of main main numbers. Then using a loop we can iterate over and find the value.
TC: O(N)
SC: O(1)
*/
class Solution {
public:
int romanToInt(string s) {
    unordered_map<char, int> dict{{'I', 1},
                                  {'V', 5},
                                  {'X', 10},
                                  {'L', 50},
                                  {'C', 100},
                                  {'D', 500},
                                  {'M', 1000}};
    int ans = 0, n = s.size();
    for(int i = 0; i < n; i++) {
        if(dict[s[i]] < dict[s[i + 1]])
            ans -= dict[s[i]];
        else
            ans += dict[s[i]];
    }
    return ans;
    }
};
