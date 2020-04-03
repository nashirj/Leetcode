/**
53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

// my first dp solution!!
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        vector<int> dp(n,0);
        dp[0] = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = nums[i] + std::max(0, dp[i-1]);
            maxSum = std::max(maxSum, dp[i]);
        }
        
        return maxSum;    
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int tempMax = nums[i];
            for (int j = i+1; j < nums.size(); j++) {
                maxSum = (tempMax > maxSum) ? tempMax : maxSum;
                tempMax += nums[j];
            }
            maxSum = (tempMax > maxSum) ? tempMax : maxSum;
        }
        return maxSum;
            
    }
};