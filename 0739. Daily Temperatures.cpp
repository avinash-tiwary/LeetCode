// LeetCode: 739. Daily Temperatures
// Link: https://leetcode.com/problems/daily-temperatures

// ========================== MonoTonic Stack ========================
/*
This Problem is same as -- 496. Next Greater Element I.
First create a stack of pair of <int, int>.
Itterate over the array in backward direction.
If Stack is empty then you don't get any warmer day ahead than that day.
If top element of stack has temperature greater than today then that is the next warmer day.
So index of that warmer day (on top of stack) minus today's index is the day you need to wait to get next warmer day.
Now insert today's date in the stack as top element as pair: pair <today's temp, today's index>.
If we have top element of stack as colder day or equal temp as of today then pop the top till you either get warmer day or empty stack.
If you get warmer day then that will be the next warmer day but if you get empty stack then you don't get any warmer day ahead.
TC: O(N)
SC: O(N)
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> mono;
        int n = temperatures.size();
        vector<int>res(n, 0);

        for(int i = n-1; i >= 0; i--){
            if(!mono.empty() && mono.top().first > temperatures[i]){
                res[i] = mono.top().second - i; 
                mono.push({temperatures[i], i});
            }
            else {
                while(!mono.empty() && mono.top().first <= temperatures[i]) mono.pop();
                if(!mono.empty()) res[i] = mono.top().second - i;
                mono.push({temperatures[i], i});
            }
        }
        return res;
    }
};
