// LeetCode: 8. String to Integer (atoi)
// Link: https://leetcode.com/problems/string-to-integer-atoi

// ======================= USING HASH-MAP ============================================
/*
Note that question have a lot of eadge cases.
This solution is brut-force.
*/
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, i = 0;
        unordered_set<char> hash = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string num = "";
        for(;i<s.length(); i++) {
            if (s[i] == ' ' && num.size() == 0) continue;
            else if (s[i] == '0' && (s[i+1] == '-' || s[i+1] == '+')) break;
            else if((s[i] == '-' || s[i] == '+') && num.size() == 0) num += s[i];
            else if((s[i] == '+') && num.size() == 0) sign = 1;
            else if (hash.find(s[i]) != hash.end()) num+= s[i];
            else break;
        }
        if (num[0] == '+') num.erase(0,1);
        else if (num[0] == '-') {
            sign = -1;
            num.erase(0,1);
        }
        while(num[0] == '0')
            num.erase(0,1);

        int n = num.length();
        if (n > 10 && sign == -1) return INT_MIN;
        else if (n > 10 && sign == 1) return (INT_MAX);
        long ans = 0;
        for (int it:num)
        {
            ans += (it - '0')*pow(10, n-1);
            n--;
        }
        if (ans > INT_MAX && sign == -1) return INT_MIN;
        else if (ans > INT_MAX && sign == 1) return (INT_MAX)*sign;
        return sign*ans;
    }
};
