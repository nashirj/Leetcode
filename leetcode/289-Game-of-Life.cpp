/*
289. Game of Life
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:
Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]

Follow up:
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

class Solution {
public:
    const int DEAD = 0, ALIVE = 1, BORN = 2, DIED = 3;
    
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        //safety check against empty board, ensures don't access 0th element and cause segfault
        if (rows == 0)
            return;
        int cols = board[0].size();
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int neighbors = numNeighbors(i, j, board, rows, cols);
                if (board[i][j] == DEAD) {
                    // rule 4
                    if (neighbors == 3){
                        board[i][j] = BORN;
                    }
                }
                else { //cell is alive
                    // rule 1 and rule 3
                    if (neighbors < 2 || neighbors > 3) {
                        board[i][j] = DIED;
                    }
                    // rule 2 is implicit, stays alive, don't change anything
                }
            }
        }
        
        //reset all dummy vals
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == BORN) {
                    board[i][j] = ALIVE;
                }
                if (board[i][j] == DIED) {
                    board[i][j] = DEAD;
                }
            }
        }
    }
    int numNeighbors(int row, int col, vector<vector<int>>& board, int rows, int cols) {
        //pair is row and column
        int count = 0;
        //increment up to 3, since this is range for neighbors
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                //if examining curr cell, continue
                if (i == 1 && j == 1) {
                    continue;
                }
                if (row-1+i < rows && row-1+i >= 0 && col-1+j < cols && col-1+j >= 0) {
                    if (board[row-1+i][col-1+j] == ALIVE || board[row-1+i][col-1+j] == DIED) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    const int DEAD = 0, ALIVE = 1;
    
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        if (rows == 0)
            return;
        int cols = board[0].size();
        vector<vector<int>> copy(rows, vector<int>(cols));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int cell = board[i][j];
                int neighbors = numNeighbors(i, j, board, rows, cols);
                if (cell == DEAD && neighbors == 3){
                    copy[i][j] = ALIVE;
                }
                else { //cell is alive
                    if (neighbors < 2 || neighbors > 3) {
                        copy[i][j] = DEAD;
                    }
                    else {
                        copy[i][j] = ALIVE;
                    }
                }
            }
        }
        board = copy;
    }
    int numNeighbors(int row, int col, vector<vector<int>>& board, int rows, int cols) {
        //pair is row and column
        int count = 0;
        //increment up to 3, since this is range for neighbors
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                if (row-1+i < rows
                    && row-1+i >= 0 
                    && col-1+j < cols
                    && col-1+j >= 0
                    && board[row-1+i][col-1+j] == ALIVE) {
                    count++;
                }
            }
        }
        return count;
    }
};


class Solution {
public:
    const int DEAD = 0, ALIVE = 1;
    
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        if (rows == 0)
            return;
        int cols = board[0].size();
        vector<vector<int>> newBoard(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int cell = board[i][j];
                int neighbors = numNeighbors(i, j, board, rows, cols);
                if (cell == DEAD) {
                    if (neighbors == 3){
                        newBoard[i][j] = ALIVE;
                    }
                }
                else { //cell is alive
                    if (neighbors < 2 || neighbors > 3) {
                        newBoard[i][j] = DEAD;
                    }
                    else {
                        newBoard[i][j] = ALIVE;
                    }
                }
            }
        }
        board = newBoard;
    }
    int numNeighbors(int row, int col, vector<vector<int>>& board, int rows, int cols) {
        //pair is row and column
        int count = 0;
        //upper left
        if (row-1 >= 0 && col - 1 >= 0 && board[row-1][col-1] == ALIVE) {
            count++;
        }
        //above
        if (row-1 >= 0 && board[row-1][col] == ALIVE) {
            count++;
        }
        //upper right
        if (row-1 >= 0 && col + 1 < cols && board[row-1][col+1] == ALIVE) {
            count++;
        }
        //left
        if (col-1 >= 0 && board[row][col-1] == ALIVE) {
            count++;
        }
        //right
        if (col+1 < cols && board[row][col+1] == ALIVE) {
            count++;
        }
        //lower left
        if (row+1 < rows && col - 1 >= 0 && board[row+1][col-1] == ALIVE) {
            count++;
        }
        //below
        if (row+1 < rows && board[row+1][col] == ALIVE) {
            count++;
        }
        //lower right
        if (row+1 < rows && col + 1 < cols && board[row+1][col+1] == ALIVE) {
            count++;
        }
        return count;
    }
};