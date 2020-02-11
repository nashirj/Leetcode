/*
58. Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/



class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0, sum = 0, ans = 0, len = s.length();
        while (i < len) {
            if (s[i++] != ' ') {
                sum++;
                ans = sum;
            } else {
                sum = 0;
            }
        }
        return ans;
    }
};




class Solution {
public:
    int lengthOfLastWord(string s) {
        int curr = s.length();
        int res = 0;
        while (curr >= 0) {
            // use prefix operator since initially curr is out of bounds
            if (s[--curr] != ' ') {
                break;
            }
        }
        while (curr >= 0) {
            if (s[curr--] == ' ') {
                break;
            }
            res++;
        }
        return res;
    }
};





class Solution {
public:
    int lengthOfLastWord(string s) {
        int curr = s.length();
        int res = 0;
        while (curr >= 0) {
            // use prefix operator since initially curr is out of bounds
            if (s[--curr] != ' ') {
                break;
            }
        }
        if (curr >= 0) { // if we didn't check all elements
            while (curr >= 0) {
                if (s[curr--] == ' ') {
                    break;
                }
                res++;
            }
        }
        return res;
    }
};