// LeetCode: 11. Container With Most Water
// Link: https://leetcode.com/problems/container-with-most-water

// ========================== BRUT-FORCE APPROACH ======================
/*
Iterate over the array with two nested loop.
We can use either recursive or iterative approach;
TC: O(N^2)
SP: O(1) for iterative
SP: O(1) + O(N) stack space for recursive
*/
class Solution {
public:
    void helper(int ind, int &ans, vector<int> &height){
        if(ind == height.size()) return;
        for(int i = ind+1; i < height.size(); i++) {
            int area = (i - ind)*(min(height[ind], height[i]));
            if(area > ans) ans = area;
        }
        helper(ind+1, ans, height);
    }
    
    int maxArea(vector<int>& height) {
        int ans = 0;
        helper(0, ans, height);
        return ans;
    }
};

// ======================== TWO-POINTER APPROACH ===========================
/*
This is optimised approach;
Initialize two pointers 'start' and 'end' from both end of the array. Find the area between two point.
Now compare the height of the pillar at both end. Move the pointer from the smaller side. Store the max
area in the process. Retuen the max area.
TC: O(N)
SC: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int start = 0;
        int end = height.size() - 1;
        int area = 0;
        while(start < end)
        {
            area = max(area, (end-start)*min(height[start], height[end]));
            if (height[start] > height[end]) end--;
            else start++;
        }
        return area;
    }
};
