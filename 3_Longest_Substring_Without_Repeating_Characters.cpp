// LeetCode: 3. Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

//===================== Two-Pointer Using Hash-Map =======================================

/*
Start the itteration with two pointers i ans j both starting from 0th index.
As with move ahead with j pointer over the string, i pointer with keep track of intial char of the substring.
Put every char you encounter at ith pos into hash map. And cheak if upcoming char is allready inside the hash
map or not. If you encounter any duplicates, just move your i pointer by 1, also remove previous ith char from 
hash map. And store the length of substrin as j-i+1. find the max of all the substring which don't have the duplicates.
TC: O(N)
SC: O(N)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_set<char> bucket;
        while(i < n && j < n)
        {
            if(bucket.find(s[i]) == bucket.end())
            {
                bucket.insert(s[i++]);
                ans = max(ans,i - j);
            }
            else
            {
                bucket.erase(s[j++]);
            }
        }
        return ans;
    }
};

// ======================= Another Optimised Approach =============================
/*
In this approach create a hashmap as list (char hash[256] = {}) that will store the location of any char in char
TC: O(N)
SC: O(1)
*/
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
