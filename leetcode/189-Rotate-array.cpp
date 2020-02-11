/*
189 - Rotate Array
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

//SOLUTION 1 - O(n) space, O(n) time
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (k == 0 || len == 0)
            return;
        vector<int> rtn(len);
        for (int i = 0; i < len; i++)
        {
            rtn[(i + k) % len] = nums[i];
        }
        
        nums = rtn;
        
    }
};

//SOLUTION 2 - O(1) space, O(n) time
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (k == 0 || len == 0)
            return;
        vector<int> rtn(len);
        for (int i = 0; i < len; i++)
        {
            rtn[(i + k) % len] = nums[i];
        }
        
        nums = rtn;
        
    }
};