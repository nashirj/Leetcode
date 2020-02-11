/*
73. Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:
Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:
Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int numRows = matrix.size();
        if (numRows == 0)
            return;
        int numCols = matrix[0].size();
        
        vector<bool> colHasZero(numCols, false);
        vector<bool> rowHasZero(numRows, false);
        
        for (int row = 0; row < numRows; row++){
            for (int col = 0; col < numCols; col++){
                if (matrix[row][col] == 0){
                    //save column for later
                    colHasZero[col] = true;
                    //save row for later
                    rowHasZero[row] = true;
                }
            }
            if (rowHasZero[row]){
                for (int i = 0; i < numCols; i++)
                    matrix[row][i] = 0;
            }       
        }
        
        for (int col = 0; col < numCols; col++){
            if (colHasZero[col]){
                for (int row = 0; row < numRows; row++)
                    matrix[row][col] = 0;
            }
        }
        
    }
};