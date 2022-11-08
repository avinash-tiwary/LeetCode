// 1. Two Sum: https://leetcode.com/problems/two-sum/

// ============ Brut-Force Approach: ======================================
/*
For each element in array traverse through the array again with nested loop.
It requires two loop;
TC: O(N^2)
SC: O(1)
*/


// ============ Optimum Approach: ==========================================
/*
Traverse through the array and store the each element and it's index you come across in a hash map.
Also keep looking for an element equal to target - current element in the hash map.
If you found this element return current index and the index of the element found in 
hash map.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>m;
        vector<int>res;
        
        for(int i = 0; i <nums.size(); i++) {
            if(m.find(target - nums[i]) != m.end()) {
                res.push_back(i);
                res.push_back(m[target - nums[i]]);
                return res;
            } 
            else m[nums[i]] = i;
        }
        return res;
    }
};
