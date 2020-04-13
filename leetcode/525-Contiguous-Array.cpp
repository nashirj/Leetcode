/**
525. Contiguous Array
Medium

1436

82

Add to List

Share
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:

Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:

Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> mapping;
        int max_length = 0;
        int count = 0;
        mapping[count] = -1; // this covers if the whole subarray is contiguous
        for (int i = 0; i < nums.size(); i++) {
            count += (nums[i] == 0) ? -1 : 1;
            if (mapping.find(count) != mapping.end()) {
                max_length = max(max_length, i - mapping[count]);
                continue;
            }
            mapping[count] = i;
        }
        return max_length;
    }
};
