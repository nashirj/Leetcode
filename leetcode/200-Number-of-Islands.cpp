/**
200. Number of Islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input:
11110
11010
11000
00000
Output: 1

Example 2:
Input:
11000
11000
00100
00011
Output: 3
*/

// O(mn) solution with constant space that modifies input array
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        if (!height) return 0;
        int width = grid[0].size();
        int num_islands = 0;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '1') {
                    //DFS on all stones that are 1s, marking them as explored
                    markConnectedStones(grid, i, j, width, height);
                    num_islands++;
                }
            }
        }
        return num_islands;
    }
    void markConnectedStones(vector<vector<char>>& grid,
             int r, int c, int w, int h) {
        if (r < 0 || r == h || c < 0 || c == w || grid[r][c] != '1')
            return;
        grid[r][c] = '0';
        markConnectedStones(grid, r+1, c, w, h);
        markConnectedStones(grid, r-1, c, w, h);
        markConnectedStones(grid, r, c+1, w, h);
        markConnectedStones(grid, r, c-1, w, h);
    }
};

// solution that does not modify input array
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        if (!height) return 0;
        int width = grid[0].size();
        vector<vector<bool>> explored(height, vector<bool>(width, false));
        int num_islands = 0;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '1' && !explored[i][j]) {
                    //DFS on all stones that are 1s, marking them as explored
                    markConnectedStones(grid, i, j, width, height, explored);
                    num_islands++;
                } else {
                    explored[i][j] = true;
                }
            }
        }
        return num_islands;
    }
    void markConnectedStones(vector<vector<char>>& grid,
             int r, int c, int w, int h,
             vector<vector<bool>>& explored) {
        if (r < 0 || r == h || c < 0 || c == w || grid[r][c] != '1' || explored[r][c])
            return;
        explored[r][c] = true;
        markConnectedStones(grid, r+1, c, w, h, explored);
        markConnectedStones(grid, r-1, c, w, h, explored);
        markConnectedStones(grid, r, c+1, w, h, explored);
        markConnectedStones(grid, r, c-1, w, h, explored);
    }
};