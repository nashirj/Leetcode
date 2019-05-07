/*
75. Sort Colors
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

/**
 * One pass algorithm
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        int j = n-1;
        while (i < j){
            if (nums[i] < nums[j])
                i++;
            else{
                swap(nums[i], nums[j]);
                j--;
            }
        }
    }
};

/**
 * Two pass algorithm
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int num0 = 0;
        int num1 = 0;
        int num2 = 0;
        
        for (int i : nums){
            if (i == 0)
                num0++;
            else if (i == 1)
                num1++;
            else if (i == 2)
                num2++;
        }
        int i = 0;
        while (i < num0)
            nums[i++] = 0;
        while (i < num0 + num1)
            nums[i++] = 1;
        while (i < n)
            nums[i++] = 2;
    }
};