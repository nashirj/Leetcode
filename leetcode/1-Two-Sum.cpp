/**
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

// O(N) using map, one pass
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices(2);
        map<int, int> complements;
        for (int i = 0; i < nums.size(); i++) {
            if (complements.find(nums[i]) != complements.end()) {
                indices[0] = complements[nums[i]];
                indices[1] = i;
                break;
            }
            complements.insert(std::pair<int,int>(target-nums[i], i));
        }
        return indices;
    }
};


// O(N) using set, two passes
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices(2);
        unordered_set<int> complements;
        int comp;
        
        for (int i = 0; i < nums.size(); i++) {
            if (complements.find(nums[i]) != complements.end()) {
                indices[0] = i;
                comp = target-nums[i];
                break;
            }
            complements.insert(target-nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == comp) {
                indices[1] = i;
                break;
            }
        }
        return indices;
    }
};

// O(n^2) using no extra space
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices(2);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    indices[0] = i;
                    indices[1] = j;
                }
            }
        }
        return indices;
    }
};