// LeetCode: 496. Next Greater Element I
// Link: https://leetcode.com/problems/next-greater-element-i

// ===================== BrutForce Method ============================
/*
Iterate over the loop using two nested loop and find the next greater element.
TC: O(N^2)
SC: O(1)
*/

// ===================== Using Monotonic Stack =======================
/*
Create a empty stack. And a map to store the greater element of each number.
Iterate over the nums2 array and do the following steps:
1. Iterate the nums2 (bigger array) in reverse.
2. If stack is empty then push the current element in the stack and in the map for
   current element greater element would be -1.
3. If current element is smaller than the top of stack then put the top element of 
   the stack as the grater element of the current element in the map.
4. If top of element is smaller than current element then pop the top element till we
   get the top element as greater than current element or stack is empty. 
5. And update the map as rule no. 2 & 3.
6. Now we can itterate over the nums1 (subset array) and then we can return the answer.
TC: O(N) : Because while loop is not running for n times it will only run for very few times. And ofcourse O(N) is approx TC.
SC: O(N)
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int>mono;
        unordered_map<int, int> m;
        for(int i = n-1; i >= 0; i--){
            if(!mono.empty() && mono.top() > nums2[i]) {
                m[nums2[i]] = mono.top();
                mono.push(nums2[i]);
            }
            else{
                while(!mono.empty() && mono.top() < nums2[i]) mono.pop();
                if(mono.empty()) m[nums2[i]] = -1;
                else m[nums2[i]] = mono.top();
                mono.push(nums2[i]);
            }
        }
        vector<int>res;
        for(int num:nums1){
            res.push_back(m[num]);
        }
        return res;
    }
};
