/*
5. Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/


/*
NEED TO SOLVE THIS WITH DP
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int sLen = s.size();
        if (sLen == 0)
            return "";
        
        int maxStart = 0, maxEnd = 0;
        
        for (int slow = 0; slow < sLen; slow++){
            //four things keeping track, slow, fast, left, right
            for (int fast = slow; fast < sLen; fast++){
                if (s[slow] == s[fast]){
                    int start = slow + 1, end = fast - 1; //already did s[slow] == s[fast] comparison
                    while(start < end){
                        if (s[start] != s[end])
                            break;
                        start++;
                        end--;
                    }
                    if (start >= end){
                        if ((fast - slow) > (maxEnd - maxStart)){
                            maxStart = slow;
                            maxEnd = fast;
                        }
                    }
                }
            }
        }
        
        return s.substr(maxStart, maxEnd - maxStart + 1);
        
    }
};