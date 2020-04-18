/**
64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/


// DP solution!

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
        if (!height) return 0;
        int width = grid[0].size();
        vector<vector<int>> min_paths(height, vector<int>(width, grid[0][0]));
        
        // assigned val to min_paths[0][0] during initialization
        // first row cells can only be reached from the left
        for (int col = 1; col < width; col++) {
            min_paths[0][col] = min_paths[0][col-1]+grid[0][col];
        }
        // first col cells can only be reached from above
        for (int row = 1; row < height; row++) {
            min_paths[row][0] = min_paths[row-1][0]+grid[row][0];
        }
        
        for (int i = 1; i < height; i++) {
            for (int j = 1; j < width; j++) {
                min_paths[i][j] = grid[i][j] + min(min_paths[i-1][j], min_paths[i][j-1]);
            }
        }
        
        return min_paths[height-1][width-1];
    }
};



// Recursive solution hits time limit exceeded
class Solution {
public:
    int min_path = INT_MAX;
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
        if (!height) return 0;
        int width = grid[0].size();
        vector<vector<int>> min_path_to_cell(height, vector<int>(width, INT_MAX));
        return minPath(grid, 0, 0, height, width, 0, min_path_to_cell);
    }
    int minPath(vector<vector<int>>& grid, int r, int c, int h, int w, int curr_path,
               vector<vector<int>>& min_path_to_cell) {
        if (r == h || r < 0 || c == w || c < 0 || curr_path >= min_path_to_cell[r][c]) {
            return INT_MAX;
        }
        if (r == h-1 && c == w-1) {
            min_path = curr_path+grid[r][c];
            return min_path;
        }
        curr_path += grid[r][c];
        min_path_to_cell[r][c] = curr_path;
        
        int down = minPath(grid, r+1, c, h, w, curr_path, min_path_to_cell);
        int right = minPath(grid, r, c+1, h, w, curr_path, min_path_to_cell);
        return min(down, right);
    }
};