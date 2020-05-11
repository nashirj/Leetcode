/**
733. Flood Fill
An image is represented by a 2-D array of integers, each integer representing
    the pixel value of the image (from 0 to 65535).
Given a coordinate (sr, sc) representing the starting pixel (row and column)
    of the flood fill, and a pixel value newColor, "flood fill" the image.
To perform a "flood fill", consider the starting pixel, plus any pixels connected
    4-directionally to the starting pixel of the same color as the starting pixel,
    plus any pixels connected 4-directionally to those pixels (also with the same
    color as the starting pixel), and so on. Replace the color of all of the
    aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

Note:
The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

// Recursive DFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) {
            fillColor(image, sr, sc, newColor, image[sr][sc]);
        }
        return image;
    }
    // DFS fill
    void fillColor(vector<vector<int>>& image, int row, int col, int newColor, int oldColor) {
        if (row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != oldColor) {
            return;
        }
        image[row][col] = newColor;
        fillColor(image, row-1, col, newColor, oldColor);
        fillColor(image, row+1, col, newColor, oldColor);
        fillColor(image, row, col-1, newColor, oldColor);
        fillColor(image, row, col+1, newColor, oldColor);
        return;
    }
};

// Iterative BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // do BFS from starting pos and change each node to newColor
        int rows = image.size();
        if (!rows) {
            return image;
        }
        int cols = image[0].size();
        queue<pair<int, int>> pixels;
        pixels.push(pair<int,int>(sr,sc));
        int s_color = image[sr][sc]; // original color to be replaced
        if (s_color == newColor) {
            return image;
        }
        image[sr][sc] = newColor;
        while (!pixels.empty()) {
            pair<int,int> curr = pixels.front();
            pixels.pop();
            int ccolor;
            if (curr.first > 0) {
                ccolor = image[curr.first-1][curr.second];
                if (ccolor == s_color) {
                    // by setting color here we ensure we don't visit pixels more than once
                    image[curr.first-1][curr.second] = newColor;
                    pixels.push(pair<int,int>(curr.first-1,curr.second));
                }
            }
            if (curr.first+1 < rows) {
                ccolor = image[curr.first+1][curr.second];
                if (ccolor == s_color) {
                    image[curr.first+1][curr.second] = newColor;
                    pixels.push(pair<int,int>(curr.first+1,curr.second));
                }
            }
            if (curr.second > 0) {
                ccolor = image[curr.first][curr.second-1];
                if (ccolor == s_color) {
                    image[curr.first][curr.second-1] = newColor;
                    pixels.push(pair<int,int>(curr.first,curr.second-1));
                }
            }
            if (curr.second+1 < cols) {
                ccolor = image[curr.first][curr.second+1];
                if (ccolor == s_color) {
                    image[curr.first][curr.second+1] = newColor;
                    pixels.push(pair<int,int>(curr.first,curr.second+1));
                }
            }
        }
        return image;
    }
};