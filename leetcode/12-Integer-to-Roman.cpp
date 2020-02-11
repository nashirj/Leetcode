/*
12. Integer to Roman

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/



// OPTIMIZED

class Solution {
public:
    string intToRoman(int num) {
        string str;
        while (num - 1000 >= 0) {
            num -= 1000;
            str += 'M';
        }
        if (num >= 900) {
            num -= 900;
            str += "CM";
        } else if (num >= 500) {
            num -= 500;
            str += "D";
        } else if (num >= 400) {
            num -= 400;
            str += "CD";
        }
        while (num - 100 >= 0) {
            num -= 100;
            str += "C";
        }
        if (num >= 90) {
            num -= 90;
            str += "XC";
        } else if (num >= 50) {
            num -= 50;
            str += "L";
        } else if (num >= 40) {
            num -= 40;
            str += "XL";
        }
        while (num - 10 >= 0) {
            num -= 10;
            str += "X";
        }
        if (num >= 9) {
            num -= 9;
            str += "IX";
        } else if (num >= 5) {
            num -= 5;
            str += "V";
        } else if (num >= 4) {
            num -= 4;
            str += "IV";
        }
        while (num - 1 >= 0) {
            num -= 1;
            str += "I";
        }
        return str;
    }
};


// FIRST SOLUTION
class Solution {
public:
    string intToRoman(int num) {
        stringstream str;
        while (num - 1000 >= 0) {
            num -= 1000;
            str << 'M';
        }
        int count = 0;
        count = reduce_greedily(&num, 100);
        if (count == 9) {
            str << "CM";
        } else if (count == 4) {
            str << "CD";
        } else {
            str << parse(count, 'D', 'C');
        }
        count = reduce_greedily(&num, 10);
        if (count == 9) {
            str << "XC";
        } else if (count == 4) {
            str << "XL";
        } else {
            str << parse(count, 'L', 'X');
        }
        count = reduce_greedily(&num, 1);
        while (num - 1 >= 0) {
            num -= 1;
            count++;
        }
        if (count == 9) {
            str << "IX";
        } else if (count == 4) {
            str << "IV";
        } else {
            str << parse(count, 'V', 'I');
        }
        return str.str();
    }
    int reduce_greedily(int* num, int decrement) {
        int count = 0;
        while (*num - decrement >= 0) {
            *num -= decrement;
            count++;
        }
        return count;
    }
    string parse(int count, char ch_5, char ch_1) {
        stringstream str;
        if (count >= 5) {
            str << ch_5;
            count -= 5;
        }
        while (count > 0) {
            str << ch_1;
            count--;
        }
        return str.str();
    }
    
    char i_to_r(int num) {
        switch(num) {
            case 1:
                return 'I';
            case 5:
                return 'V';
            case 10:
                return 'X';
            case 50:
                return 'L';
            case 100:
                return 'C';
            case 500:
                return 'D';
            case 1000:
                return 'M';
            default:
                return 0;
        }
    }
};