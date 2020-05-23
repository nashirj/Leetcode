/**
1277. Count Square Submatrices with All Ones
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation:
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:
Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

Constraints:
1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

// this version modifies input array, I prefer the below one even tho it uses O(mn) space
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1 && i && j) {
                    // if any of the neighbors on left, upper left, or above is 0, only add 1
                    // otherwise, all are 1, and each forms a subsquare of size k-1 with its
                    // neighbors
                    matrix[i][j] = min({matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]}) + 1;
                }
                res += matrix[i][j];
            }
        }
        return res;
    }
};

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0];
            res += dp[i][0];
        }
        for (int j = 1; j < n; j++) { // already added m[0][0]
            dp[0][j] = matrix[0][j];
            res += dp[0][j];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 1) {
                    // if any of the neighbors on left, upper left, or above is 0, only add 1
                    // otherwise, all are 1, and each forms a subsquare of size k-1 with its
                    // neighbors
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                }
                res += dp[i][j];
            }
        }
        return res;
    }
};