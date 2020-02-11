/*
448. Find All Numbers Disappeared in an Array
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        // n numbers, treat each number as an index
        for(int i = 0; i < n; i++) {
            // indexing starts from 0
            int m = abs(nums[i]) - 1;
            // mark the val at the index nums[i] as seen
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            // if this index was not marked as seen, then the number is not in the array
            // return these values
            if (nums[i] > 0) {
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        // initialize all indices to zero, decrement each time you see a val in nums
        // if an index is zero, it was not in nums, so add it to the returned vector
        vector<int> ret(n, 0);
        for (int i : nums) {
            ret[i-1]--;
        }
        
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (ret[i] == 0) {
                temp.push_back(i+1);
            }
        }
        return temp;
    }
};