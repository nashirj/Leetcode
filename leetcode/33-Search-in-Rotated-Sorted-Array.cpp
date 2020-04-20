class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return ((nums[0] == target) ? 0 : -1);
        }
        
        // find index of minimum element
        int low = 0, mid, high = n-1;
        while (low < high) {
            mid = low + (high-low)/2; // avoid overflow
            if (nums[mid] > nums[high]) { // we picked a number to the left of min
                low = mid+1;
            } else {
                high = mid; // min index is somewhere in the inclusive interval [0, mid]
            }
        }
        
        // set bounds so that we can just do binary search
        int min_index = low; // low == hi
        if (target == nums[min_index]) {
            return min_index;
        } else if (target <= nums[n-1]) {
            low = min_index;
            high = n-1;
        } else if (min_index > 0 && target <= nums[min_index-1]) {
            low = 0;
            high = min_index-1;
        }
        
        // binary search
        while (low <= high) {
            int mid = low + (high-low)/2; // avoid overflow
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid-1;
            } else { // nums[mid] < target
                low = mid+1;
            }
        }
        return -1;
    }
};