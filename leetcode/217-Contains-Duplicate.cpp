/**
217. Contains Duplicate

Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:
Input: [1,2,3,1]
Output: true

Example 2:
Input: [1,2,3,4]
Output: false

Example 3:
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

// O(nlogn), no extra space
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }
};

// O(n), most expensive thing is constructing a hash table
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > std::unordered_set<int>(nums.begin(), nums.end()).size();
        
    }
};

// this solution is O(n)? lookups in unordered_set are O(1)
class secondSolution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> n;
        for(int i = 0, nsize = nums.size(); i < nsize; i++){
            temp = nums[i];
            if (n.find(temp) != n.end()) {
                return true;
            }
            n.insert(temp);
        }
        return false;
    }
};