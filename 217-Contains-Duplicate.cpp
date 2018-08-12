class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //is this O(n)? constructing a hash table is O(n)
        return nums.size() > std::unordered_set<int>(nums.begin(), nums.end()).size();
        
    }
};




class secondSolution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //this solution is O(nlogn)
        unordered_set<int> n;
        int nsize = nums.size();
        if (nsize <= 1)
            return false;
        int temp;
        for(int i = 0; i < nsize; i++){
            temp = nums[i];
            if (n.find(temp) == n.end())
                n.insert(temp);
            else
                return true;
        }
        return false;
        
    }
};


class firstSolution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> n;
        int nsize = nums.size();
        if (nsize <= 1)
            return false;
        for(int i = 0; i < nsize; i++){
            if (n.find(nums[i]) == n.end())
                n.insert(nums[i]);
            else
                return true;
        }
        return false;
        
    }
};