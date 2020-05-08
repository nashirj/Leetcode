/**
169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2
*/


// Boyer-Moore majority voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // guaranteed to be a majority elem, so don't need to check size
        int majorityCandidate = nums[0];
        int count = 0;
        
        for (int i : nums) {
            if (count == 0) {
                majorityCandidate = i;
            }
            // note that count can never become negative. at some point it
            // becomes zero, and then majorityCandidate changes, at which
            // point count will start increasing again
            count += (majorityCandidate == i) ? 1 : -1;
        }
        return majorityCandidate;
    }
};




class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq;
        for (int i : nums) {
            if (freq.find(i) == freq.end()) {
                freq[i] = 1;
            } else {
                freq[i]++;
            }
        }
        int majorityElement = 0;
        int majorityCount = 0;
        for (map<int,int>::iterator it = freq.begin(); it != freq.end(); it++) {
            if (it->second > majorityCount) {
                majorityCount = it->second;
                majorityElement = it->first;
            }
        }
        return majorityElement;
    }
};