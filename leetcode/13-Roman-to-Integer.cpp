/*
13. Roman to Integer

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
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:
Input: "III"
Output: 3

Example 2:
Input: "IV"
Output: 4

Example 3:
Input: "IX"
Output: 9

Example 4:
Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 5:
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

// solution from 7/19/20
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mapping = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = s.length();
        int total = 0;
        // if s[i] < s[i+1], then process both at once, else process one at a time
        for (int i = 0; i < n; i++) {
            if (i < n-1 && mapping[s[i]] < mapping[s[i+1]]) {
                total -= mapping[s[i]];
                i++;
            }
            total += mapping[s[i]];
        }
        return total;
    }
};


// SOLUTION FROM 1/15/2020
class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int total = 0;
        // if s[i] < s[i+1], then process both at once, else process one at a time
        for (int i = 0; i < n; i++) {
            if (i < n-1 && get_conv(s[i]) < get_conv(s[i+1])) {
                total -= get_conv(s[i]);
                i++;
            }
            total += get_conv(s[i]);   
        }
        return total;
    }
    int get_conv(char c) {
        switch(c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
};


// SOLUTION FROM BEFORE
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_to_int;
        roman_to_int['I'] = 1;
        roman_to_int['V'] = 5;
        roman_to_int['X'] = 10;
        roman_to_int['L'] = 50;
        roman_to_int['C'] = 100;
        roman_to_int['D'] = 500;
        roman_to_int['M'] = 1000;
        
        int total = 0;
        int i = 0;
        while (i < s.length() - 1) {
            int subtotal = 0;
            char curr = s[i], next = s[i+1];
            if (s[i] == 'I') {
                subtotal = helper(next, 'I', 'V', 'X', roman_to_int);
            } else if (s[i] == 'X') {
                subtotal = helper(next, 'X', 'L', 'C', roman_to_int);
            } else if (s[i] == 'C') {
                subtotal = helper(next, 'C', 'D', 'M', roman_to_int);
            }
            else {
                subtotal = roman_to_int[s[i]];
            }
            if (subtotal != roman_to_int[s[i]]) {
                i++;
            }
            total += subtotal;
            i++;
        }
        if (i < s.length()) {
            total += roman_to_int[s[i]];
        }
        
        return total;
    }
    
    int helper(char next, char a, char b, char c, unordered_map<char, int>& rom_to_i) {
        if (next == b) {
            return rom_to_i[b] - rom_to_i[a];
        } else if (next == c) {
            return rom_to_i[c] - rom_to_i[a];
        } else {
            return rom_to_i[a];
        }
    }
};