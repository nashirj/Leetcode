/*
88. Merge Sorted Array
Easy

850

2300

Favorite

Share
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

/*
APPROACH 4
same as APPROACH 3 just refactored
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = m-1, n2 = n-1, i = n+m-1;
        //start from end of nums1
        while(n1 >= 0 && n2 >= 0)
            nums1[i--] = (nums1[n1] >= nums2[n2]) ? nums1[n1--]: nums2[n2--];
        while(n2 >= 0)
                nums1[i--] = nums2[n2--];
        while(n1 >= 0)
                nums1[i--] = nums1[n1--];
    }
};


/*
APPROACH 3
O(1) space, O(m + n) time

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = m-1, n2 = n-1, i;
        //start from end of nums1
        for(i = n+m-1; i >= 0; i--){
            if(n1 < 0 || n2 < 0)
                break;
            if(nums1[n1] >= nums2[n2]){
                nums1[i] = nums1[n1--];
            }
            else{ //(nums1[n1] < nums2[n2]){
                nums1[i] = nums2[n2--];
            }
        }
        if (n1 < 0){
            while(n2 >= 0)
                nums1[i--] = nums2[n2--];
        }
        else{ //n2 < 0
            while(n1 >= 0)
                nums1[i--] = nums1[n1--];
        }
    }
};

APPROACH 2
O(n) space, O(m + n) time

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //using extra space
        vector<int> merged(m+n, 0);
        
        int n1, n2;
        n1 = n2 = 0;
        int i = 0;
        while(n1 < m && n2 < n){
            if(nums1[n1] >= nums2[n2]){
                merged[i++] = nums2[n2++];
            }
            else{ //(nums1[n1] < nums2[n2]){
                merged[i++] = nums1[n1++];
            }
        }
        if (n1 == m){
            while(n2 < n)
                merged[i++] = nums2[n2++];
        }
        else{ //n2 == n
            while(n1 < m)
                merged[i++] = nums1[n1++];
        }
        nums1 = merged;
    }
};

APPROACH 1
obviously not what asked for, but important to know how to do

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m; i < m+n; i++){
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin(), nums1.end());
        return;
    }
};
*/