// LeetCode: 26. Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array

// =================== First Approach ====================================
/*
Just use set data structure ans you will get all
the element without any duplicates.
TC: O(N)
SC: O(N)
*/

// =================== Better Approach ==================================
/*
Use two pointer approach say i and j. Move j ahead if ith element is equal to jth then
move the jth element ahead again. But if encounter different element on ith and jth index
then replace i+1st element with jth element.
TC: O(N)
SC: O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        while(j < n){
            if(nums[i] == nums[j]) j++;
            else {
                nums[++i] = nums[j++];
            }
        }
        return i+1;
    }
};
