/**
1143. Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some
    characters(can be none) deleted without changing the relative order of the remaining
    characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common
    subsequence of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Example 3:
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        vector<vector<int>> lcs(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
        
        return lcs[m][n];
    }
};


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        vector<vector<int>> lcs(m, vector<int>(n, 0));
        
        if (text1[0] == text2[0]) {
            lcs[0][0] = 1;
        }
        // initialize first row and column
        for (int i = 1; i < m; i++) {
            if (text1[i] == text2[0]) {
                lcs[i][0] = 1;
            } else {
                lcs[i][0] = lcs[i-1][0];
            }
        }
        for (int i = 1; i < n; i++) {
            if (text1[0] == text2[i]) {
                lcs[0][i] = 1;
            } else {
                lcs[0][i] = lcs[0][i-1];
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (text1[i] == text2[j]) {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
        
        
        return lcs[m-1][n-1];
    }
};