/*
268. Missing Number
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/

//APPROACH 4
//O(1) space, O(n) time with only one operation for pass through array by using Gauss's formula

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int total = (size)*(size+1)/2;
        for(int i = 0; i < size; i++){
            total -= nums[i];
        }
        
        return total;
    }
};

//APPROACH 5
//O(1) space, O(n) time using bit shift
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n, size;
        n = size = nums.size();
        
        //since nums contains n numbers and is missing exactly one number on the range [0..n−1], we know that n definitely replaces the missing number in nums. if we initialize an integer to n and XOR it with every index and value, we will be left with the missing number
        
        for(int i = 0; i < size; i++){
            n ^= i ^ nums[i];
        }
        
        return n;
    }
};

//APPROACH 3
//O(1) space, O(n) time

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int total = size;
        for(int i = 0; i < size; i++){
            total += i - nums[i];
        }
        
        return total;
    }
};


//APPROACH 2
//O(1) space, O(n^2) time

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        
        int i;
        for(i = 0; i < size + 1; i++){
            bool found = false;
            for(int j = 0; j < size; j++){
                if (nums[j] == i)
                    found = true;
            }
            if (!found)
                break;
        }
        return i;
    }
};

//APPROACH 1
//O(n) space, O(n) time

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        
        unordered_set<int> seen;
        for(int num : nums){
            seen.insert(num);
        }
        int i;
        for(i = 0; i < size; i++){
            if (seen.find(i) == seen.end())
                break;
        }
        return i;
    }
};

*/