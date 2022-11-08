// LeetCode: 4. Median of Two Sorted Arrays
// Link: https://leetcode.com/problems/median-of-two-sorted-arrays

// =============== Brut-Force Approach ===========================
/*
Merge two arrays, sort them. Then we have the length of the new array. Simply find the median as middle element.
TC: O((M+N)log(M+N))
SC: O(M+N)
*/

// ================ OPTIMAL APPROACH =============================
/*
We are given that arrays are sorted then we can take benefit of it.
Using a while loop and two pointers, one on each, we can traverse through the arrays. We can move one by one element,
counting the index of each number as if they are merged and sorted. Compare the ith and jth element from the two arrays
and then smaller one get the lower count, and then moving the pointer ahead by one, in the array with smaller element.
If any of the arrays get over then solely itereate over the array which is left over. Also noting that if length of (M+N)
is even then we need to take the average of the two middle element. otherwise return the middle element.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n =nums2.size();
        int median = (m+n)/2;
        double temp;
        int i = 0, j = 0;
        double ans;
        while(i < m && j < n && i+j <= median) {
            if(nums1[i] <= nums2[j]) {
                temp = ans;
                ans = nums1[i];
                i++;
            }
            else {
                temp = ans;
                ans = nums2[j];
                j++;
            }
        }
        while(i < m && i+j <= median) {
            temp = ans;
            ans = nums1[i];
            i++;
        }
        while(j < n && i+j <= median) {
            temp = ans;
            ans = nums2[j];
            j++;
        }
        if((m+n)%2 == 1) {
           // cout << " If ";
           return ans;
        }
        else {
            return (temp+ans)/2;
        }
    }
};
