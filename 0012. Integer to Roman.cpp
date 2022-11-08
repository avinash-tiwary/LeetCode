// LeetCode: 12. Integer to Roman
// Link: https://leetcode.com/problems/integer-to-roman

// ==================== Simple Solution ====================================================
/*
~~~~~  Not a very good question ~~~~~~~~~~~
Nothing to Explain here.
TC: O(1);
SC: O(1)
*/

class Solution {
public:
    string intToRoman(int num) {
        
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundereds[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thousands[]={"","M","MM","MMM"};
        
        return thousands[num/1000] + hundereds[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
        
    }
};
