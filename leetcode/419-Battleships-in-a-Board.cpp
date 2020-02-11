/*
419. Battleships in a Board
Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
You receive a valid board, made of only battleships or empty slots.

Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.

Example:
X..X
...X
...X
In the above board there are 2 battleships.

Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.

Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
*/


// O(1) space solution, only count the battleship's first cell, ignore all subsequent 'X's
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int num_battleships = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // only count first cells
                if (board[i][j] == '.') 
                    continue;
                if (i > 0 && board[i-1][j] == 'X') 
                    continue;
                if (j > 0 && board[i][j-1] == 'X') 
                    continue;
                num_battleships++;
            }
        }
        
        return num_battleships;
    }
};

// O(1) Space solution, only count the battleship if it is the rightmost or bottom most 'X'
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int num_battleships = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'X') {
                    if (i < rows-1 && board[i+1][j] != 'X' || i == rows-1) {
                        if (j < cols-1 && board[i][j+1] != 'X' || j == cols-1) {
                            num_battleships++;
                        }
                    }
                }
            }
        }
        
        return num_battleships;
    }
};


// First take solution
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (!board.size())
            return 0;
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> explored(rows, vector<bool>(cols, false));
        int num_battleships = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'X') {
                    if (!hasUnexploredNeighbor(board, explored, i, j)) {
                        num_battleships++;
                    }
                }
                explored[i][j] = true;
            }
        }
        return num_battleships;
    }
    bool hasUnexploredNeighbor(vector<vector<char>>& board, vector<vector<bool>>& explored, int row, int col) {
        // don't want to go out of bounds
        if (row > 0 && board[row-1][col] == 'X' && !explored[row-1][col]) {
            return true;
        }
        if (row < board.size()-1 && board[row+1][col] == 'X' && !explored[row+1][col]) {
            return true;
        }
        if (col > 0 && board[row][col-1] == 'X' && !explored[row][col-1]) {
            return true;
        }
        if (col < board[0].size()-1 && board[row][col+1] == 'X' && !explored[row][col+1]) {
            return true;
        }
        return false;
    }
};