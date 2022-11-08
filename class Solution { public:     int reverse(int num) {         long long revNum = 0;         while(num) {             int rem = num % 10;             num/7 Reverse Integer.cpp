
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
