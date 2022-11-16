// LeetCode: 374. Guess Number Higher or Lower
// Link: https://leetcode.com/problems/guess-number-higher-or-lower/description/

// ================== Binary Search ====================================
/*
It is simple binary search
TC: O(log_2 N)
SC: O(1)
*/

/** guess is already defined function passed through api;
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long up = n, low = 1;
        while(low <= up) {
            long long num = (up+low)/2;
            int response = guess(num);
            if (response == 0) return num;
            else if(response == -1) up = num-1;
            else low = num +1;
        }
        return -1;
    }
};
