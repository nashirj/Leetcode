/*
118. Pascal's Triangle

Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

//APPROACH 1
//O(n) time, no extra space, I guess O(n)?

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //(n choose k) = (n choose k-1) * ((n + 1 - k) / k)
        vector<vector<int>> triangle(numRows);
        for (int n = 0; n < numRows; n++){
            //first element of each row is always 1
            triangle[n].push_back(1);
            for (int k = 1; k <= n; k++){
                triangle[n].push_back((triangle[n][k-1] * (n + 1 - k)) / k);
            }
        }
        return triangle;
    }
};


//APPROACH 2
//O(n) time, no extra space, also O(n)?

/*
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        if (numRows > 0)
            triangle[0].push_back(1);
        
        if (numRows > 1){
            triangle[1].push_back(1);
            triangle[1].push_back(1);
        }
        
        //since first two rows are all 1s, we can start at 3rd row, i.e. n = 2
        for (int n = 2; n < numRows; n++){
            //first element of each row is always 1
            triangle[n].push_back(1);
            for (int k = 1; k < n; k++){
                triangle[n].push_back((triangle[n-1][k-1] + triangle[n-1][k]));
            }
            //last element of each row is always 1
            triangle[n].push_back(1);
        }
        return triangle;
    }
};
*/