/*
136. Single Number
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

//SPEED UP IO - cuts runtime in half!
static int x = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

//O(n) time and O(1) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++)
            res ^= nums[i];
            //if a number occurs twice, those bits will be filtered out, the only thing that remains at end is unique XOR 0, which is the same as unique
        return res;
    }
};

class firstSolution {
public:
    int singleNumber(vector<int>& nums) {
        int nsize = nums.size();
        if (nsize == 1)
            return nums[0];
        
        map<int, int> m;
        int temp;
        for(int i = 0; i < nsize; i++){
            temp = nums[i];
            if (m.find(temp) == m.end())
                m[temp] = 1;
            else
                m[temp] = 2;
        }
        
        for (auto const& x : m)
        {
            if (x.second == 1)
                return x.first;
        }
    }
};