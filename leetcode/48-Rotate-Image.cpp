/*
48. Rotate Image
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int start = 0, end = size - 1;
        while (end - start > 0){
            for (int i = start; i < end; i++){
                int first = matrix[size-end-1][i];
                matrix[size-end-1][i] = matrix[end+start-i][size-end-1]; //1 = 4
                matrix[end+start-i][size-end-1] = matrix[end][end+start-i]; //4 = 3
                matrix[end][end+start-i] = matrix[i][end]; //3 = 2
                matrix[i][end] = first; //2 = first
            }
            end--;
            start++;
        }
    }
};

/*

//CTCI solution
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //validate input
        if (n <= 1 || n != matrix[0].size())
            return;
        
        for (int layer = 0; layer < n/2; layer++){
            int first = layer;
            int last = n - layer - 1;
            for (int i = first; i < last; i++){
                int offset = i - first;
                
                //save top
                int top = matrix[first][i];
                
                //left->top
                matrix[first][i] = matrix[last-offset][first];
                
                //bottom->left
                matrix[last-offset][first] = matrix[last][last-offset];
                
                //right->bottom
                matrix[last][last-offset] = matrix[i][last];
                
                //top->right
                matrix[i][last] = top;
            }
        }
    }
};




class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int start = 0, end = size - 1;
        while (end - start > 0){
            for (int i = start; i < end; i++){
                swap(matrix[size-end-1][i], matrix[i][end]);
                swap(matrix[end][end+start-i], matrix[end+start-i][size-end-1]);
                swap(matrix[size-end-1][i], matrix[end][end-i+start]);
            }
            end--;
            start++;
        }
    }
};



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int start = 0, end = size - 1;
        while (end - start > 0){
            for (int i = start; i < end; i++){
                int x0, y0, x1, y1, x2, y2, x3, y3;
                y0 = size - end - 1;
                x0 = i;
                y1 = i;
                x1 = end;
                y2 = end;
                x2 = x1 - y1 + start;
                y3 = x2;
                x3 = size - end - 1;
                
                swap(matrix[y0][x0], matrix[y1][x1]);
                swap(matrix[y2][x2], matrix[y3][x3]);
                swap(matrix[y0][x0], matrix[y2][x2]);
            }
            end--;
            start++;
        }
    }
};
