/**
55. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/

// optimal solution! I came up with this first woot woot
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // go backwards, if can't jump from any of these indices, we know we can't jump,
        // successively make problem smaller by moving penultimate index leftward
        int n = nums.size();
        if (n < 2) {
            return true;
        }
        int l = n-1, r = n-2;
        while (l >= 0) {
            if (l + nums[l] >= r) {
                r = l;
            }
            l--;
        }
        return r == 0;
    }
};

// another good solution that goes rightwards instead of leftwards
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_dist = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (max_dist < i) {
                return false; // this means i is unreachable from earlier indices
            }
            max_dist = max(max_dist, i+nums[i]);
            if (max_dist >= n-1) {
                return true;
            }
        }
        return false;
    }
};

// iterative with lookup table - more complicated version of the first thing i came up with
class Solution {
private:
    enum Index {GOOD, BAD, UNKNOWN};
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return true;
        }
        vector<Index> good_indices(n, UNKNOWN);
        good_indices[n-1] = GOOD;
        
        for (int i = n-2; i >= 0; i--) {
            int max_valid_jump = min(n-1, nums[i]+i);
            for (int j = i + 1; j <= max_valid_jump; j++) {
                if (good_indices[j] == GOOD) {
                    good_indices[i] = GOOD;
                    break;
                }
            }
            
        }
        return good_indices[0] == GOOD;
    }
};


// iterative with lookup table
class Solution {
private:
    enum Index {GOOD, BAD, UNKNOWN};
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<Index> good_indices(n, UNKNOWN);
        good_indices[n-1] = GOOD;
        return helper(nums, good_indices, nums.size(), 0);
    }
    bool helper(vector<int>& nums, vector<Index>& good_indices, int n, int index) {
        if (n <= index) {
            return false;
        }
        if (good_indices[index] != UNKNOWN) {
            return (good_indices[index] == GOOD) ? true : false;
        }
        
        for (int i = nums[index]; i > 0; i--) {
            if (helper(nums, good_indices, n, index+i)) {
                good_indices[index] = GOOD;
                return true;
            } else {
                good_indices[index] = BAD;
            }
        }
        return false;
    }
};

// backtracking with lookup table
class Solution {
private:
    enum Index {GOOD, BAD, UNKNOWN};
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<Index> good_indices(n, UNKNOWN);
        good_indices[n-1] = GOOD;
        return helper(nums, good_indices, nums.size(), 0);
    }
    bool helper(vector<int>& nums, vector<Index>& good_indices, int n, int index) {
        if (n <= index) {
            return false;
        }
        if (good_indices[index] != UNKNOWN) {
            return (good_indices[index] == GOOD) ? true : false;
        }
        
        for (int i = nums[index]; i > 0; i--) {
            if (helper(nums, good_indices, n, index+i)) {
                good_indices[index] = GOOD;
                return true;
            } else {
                good_indices[index] = BAD;
            }
        }
        return false;
    }
};

// naive backtracking
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return helper(nums, nums.size(), 0);
    }
    bool helper(vector<int>& nums, int n, int index) {
        if (n-1 == index) {
            return true;
        } else if (n <= index) {
            return false;
        }
        for (int i = 1; i <= nums[index]; i++) {
            if (helper(nums, n, index+i)) {
                return true;
            }
        }
        return false;
    }
};