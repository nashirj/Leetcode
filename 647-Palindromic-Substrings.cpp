/*
647. Palindromic Substrings

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:

The input string length won't exceed 1000.
*/

class Solution {
public:
    int countSubstrings(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int s_len = s.length();
        int num_p_subs = s_len;
        for (int i = 0; i < s.length(); i++) {
            int upper = i + 1;
            int lower = i - 1;
            while (upper < s.length() && lower >= 0) {
                if (s[lower--] != s[upper++]) {
                    break;
                }
                num_p_subs++;
            }
            lower = i;
            upper = i + 1;
            while (lower >= 0 && upper < s.length()) {
                if (s[upper++] != s[lower--]) {
                    break;
                }
                num_p_subs++;
            }
        }
        return num_p_subs;
    }
};