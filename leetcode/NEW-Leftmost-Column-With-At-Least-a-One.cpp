/**
(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

 

Example 1:
Input: mat = [[0,0],[1,1]]
Output: 0

Example 2:
Input: mat = [[0,0],[0,1]]
Output: 1

Example 3:
Input: mat = [[0,0],[0,0]]
Output: -1

Example 4:
Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1
 

Constraints:

1 <= mat.length, mat[i].length <= 100
mat[i][j] is either 0 or 1.
mat[i] is sorted in a non-decreasing way.
*/


// O(m + n) solution
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> size = binaryMatrix.dimensions();
        int min_index = -1;
        int row = 0, col = size[1]-1;
        /**
        Start at top right corner. If a 1 is encountered, check left neighbor until zero (i.e.
        in column j). If a zero is encountered, check row i+1 starting at column j. Since rows
        are sorted, it's guaranteed that if there is a one in this row at an index less than
        min_index, there must be a one at column j. So, this is guaranteed to find the minimum.
        */
        while (row < size[0] && col >= 0) {
            if (binaryMatrix.get(row,col)) {
                min_index = col;
                col--;
            } else {
                row++;
            }
        }
        return min_index;
    }
};

// O(nlogm) solution
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> size = binaryMatrix.dimensions();
        // int rows = size[0], cols = size[1];
        int min_index = INT_MAX;
        for (int i = 0; i < size[0]; i++) {
            // binary search each row, can't do column, because they are not guaranteed sorted
            int low = 0, high = size[1]-1;
            while (low <= high) {
                int mid = low + (high-low)/2;
                if (binaryMatrix.get(i, mid) == 1) {
                    min_index = min(min_index, mid);
                    if (mid-1 <= 0 || binaryMatrix.get(i, mid-1) == 0) {
                        break;
                    } else {
                        high = mid-1;
                    }
                } else {// if (nums[mid] == 0)
                    low = mid+1;
                }
            }
        }
        return (min_index == INT_MAX) ? -1 : min_index;
    }
};


/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */
