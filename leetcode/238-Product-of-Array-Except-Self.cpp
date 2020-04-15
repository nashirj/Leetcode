/**
238. Product of Array Except Self
Medium

4109

355

Add to List

Share
Given an array nums of n integers where n > 1,  return an array output such that output[i]
is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix
of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as
extra space for the purpose of space complexity analysis.)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int num_zeros = std::count(nums.begin(), nums.end(), 0);
        if (num_zeros > 1) {
            return vector<int>(nums.size(), 0);
        }
        vector<int> products(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
        }
        return products;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n_size = nums.size();
        vector<int> left(n_size);
        left[0] = 1;
        vector<int> right(n_size);
        right[n_size-1] = 1;
        for (int i = 1; i < n_size; i++) {
            left[i] = left[i-1]* nums[i-1];
            right[n_size-i-1] = right[n_size-i]* nums[n_size-i];
        }
        vector<int> products(n_size);
        for (int i = 0; i < nums.size(); i++) {
            products[i] = left[i] * right[i];
        }
        return products;
    }
};