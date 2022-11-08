// LeetCode: 7. Reverse Integer
// Link: https://leetcode.com/problems/reverse-integer

// ============== Another Approach ===================
/*
Just take remainder of the number by taking modulo, also devide the number;
then initialize the reverse number with zero and inside loop
reverse num = reverse num * 10 + remainder;
Then in the end handle the eadge case;
TC: O(logN)
SC: O(1)
*/

class Solution {
public:
    int reverse(int num) {
        long long revNum = 0;
        while(num) {
            int rem = num % 10;
            num /= 10;
            revNum = revNum*10 + rem;
        }
        revNum = revNum > pow(2, 31)-1 ? 0 : revNum;
        revNum = revNum < -pow(2, 31) ? 0 : revNum;
        return revNum;
    }
};
