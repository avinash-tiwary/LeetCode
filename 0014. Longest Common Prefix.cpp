// LeetCode: 14. Longest Common Prefix
// Link: https://leetcode.com/problems/longest-common-prefix

// ======================Brut-Force Method =========================
/*
Compare the each letter of each words and append the letter to a string variable and return the answer when you get first mismatch;
Also don't forget to handle two eadge cases, one when there is no words or when only one word.
TC: O(N)
SC: O(1)
-- but for answer we need O(N) space;
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        string ans = "";
        if(str.size() == 1) return str[0];
        if (!str[0].size()) return ans;
        int ind = 0;
        while (ind < str[0].size()) {
            char c = str[0][ind];
            for (int i = 0; i < str.size(); i++) {
                if (c != str[i][ind]) return ans;
            }
            ans += c;
            ind++;
        }
        return ans;
    }
};

// ===================== Another Approach =======================
/*
Sort the vector of strings and then compare the first and last words, because they will be most different.
Although it seem fast on leetcode but it is not a good solution. 
TC: O(NlogN)
SC: O(1)
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string ans = "";
        
        string a = strs[0], b = strs[n-1];
        for(int i = 0; i < a.length(); i++){
            if(a[i] == b[i]) ans += a[i];
            else break;
        }
        return ans;
    }
};
