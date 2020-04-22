/**
560. Subarray Sum Equals K
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/


// one pass! O(n) space and O(n) time.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int num_sums = 0, n = nums.size(), total_sum = 0;
        // given that n \in [1, 20000]
        map<int,int> sums;
        // vector<int> sums(n, 0);
        sums[0] = 1;
        
        for (int i = 0; i < n; i++) {
            total_sum += nums[i];
            // there is a subarray between two elements of size k
            // even if this is from beginning, this will work because
            // we stored sums[0] = 1
            if (sums.find(total_sum-k) != sums.end()) {
                // each time we find a new subarray with a sum of zero between,
                // each previous subarray becomes a new valid subarray up to the current
                // element
                num_sums += sums[total_sum-k];
            }
            if (sums.find(total_sum) != sums.end()) {
                sums[total_sum]++;
            } else {
                sums[total_sum] = 1;
            }
        }
        
        return num_sums;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int num_sums = 0, n = nums.size();
        // given that n \in [1, 20000]
        vector<int> sums(n, 0);
        sums[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i-1]+nums[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (sums[j]-sums[i]+nums[i] == k) {
                    num_sums++;
                }
            }
        }
        
        return num_sums;
    }
};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int num_sums = 0, n = nums.size();
        // given that n \in [1, 20000]
        vector<vector<int>> sums(n, vector<int>(n,0));
        sums[0][0] = nums[0];
        num_sums += (sums[0][0] == k);
        
        for (int i = 1; i < n; i++) {
            sums[0][i] = sums[0][i-1]+nums[i];
            num_sums += (sums[0][i] == k);
        }
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j++) {
                sums[i][j] = sums[i-1][j]-sums[i-1][i-1];
                num_sums += (sums[i][j] == k);
            }
        }
        
        return num_sums;
    }
};