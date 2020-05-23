/*
221. Maximal Square
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:
Input:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
**/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = (m > 0) ? matrix[0].size() : 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int max_len = 0;
        
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if (matrix[i-1][j-1] == '1') {
                    // if any of the neighbors on left, upper left, or above is 0, only add 1
                    // otherwise, all are 1, and each forms a subsquare of size k-1 with its
                    // neighbors
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                    max_len = max(max_len, dp[i][j]);
                }
            }
        }
        
        return max_len * max_len;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = (m > 0) ? matrix[0].size() : 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int max_len = 0;
        
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0]-'0';
            max_len = max(max_len, dp[i][0]);
        }
        for (int j = 1; j < n; j++) { // already added m[0][0]
            dp[0][j] = matrix[0][j]-'0';
            max_len = max(max_len, dp[0][j]);
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j]-'0' == 1) {
                    // if any of the neighbors on left, upper left, or above is 0, only add 1
                    // otherwise, all are 1, and each forms a subsquare of size k-1 with its
                    // neighbors
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                }
                max_len = max(max_len, dp[i][j]);
            }
        }
        
        return max_len * max_len;
    }
};