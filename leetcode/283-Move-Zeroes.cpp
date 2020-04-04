/**
283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //two pass algorithm
        //count num zeros, move non-zero vals up, fill zeros at end
        int nsize = nums.size();
        
        int num_zeroes = 0;
        // count zeroes
        for (int i : nums) {
            if (!i) {
                num_zeroes++;
            }
        }
        
        int curr = 0;
        // move all nonzero vals to start of nums
        for (int i = 0; curr < nsize-num_zeroes; i++) {
            if(nums[i]) {
                nums[curr++] = nums[i];
            }
        }

        //fill zeroes at end of nums
        while (num_zeroes) {
            nums[nsize-num_zeroes--] = 0;
        }
    }
};