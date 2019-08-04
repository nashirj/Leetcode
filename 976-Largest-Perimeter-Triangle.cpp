/*
976. Largest Perimeter Triangle
Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return 0. 

Example 1:
Input: [2,1,2]
Output: 5

Example 2:
Input: [1,2,1]
Output: 0

Example 3:
Input: [3,2,3,4]
Output: 10

Example 4:
Input: [3,6,2,3]
Output: 8
 
Note:

3 <= A.length <= 10000
1 <= A[i] <= 10^6
*/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int alen = A.size();
        
        for (int i = alen - 3; i >= 0; i--) {
            if (A[i] + A[i+1] > A[i+2])
                return A[i] + A[i+1] + A[i+2];
        }
        
        return 0;
    }
};



class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int alen = A.size();
        
        for (int i = alen - 1; i >= 2; i--) {
            for (int j = i - 1; j >= 1; j--) {
                for (int k = j - 1; k >= 0; k--) {
                    if (A[i] >= A[j] + A[k])
                        break;
                    return A[i] + A[j] + A[k];
                }
            }
        }
        
        return 0;
    }
};



class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int alen = A.size();
        int max_sum = 0;
        
        for (int i = alen - 1; i >= 2; i--) {
            for (int j = i - 1; j >= 1; j--) {
                for (int k = j - 1; k >= 0; k--) {
                    if (A[i] >= A[j] + A[k])
                        break;
                    int temp_sum = A[i] + A[j] + A[k];
                    if (temp_sum <= max_sum)
                        break;
                    max_sum = temp_sum;
                }
                if (max_sum > 0)
                    break;
            }
            if (max_sum > 0)
                break;
        }
        return max_sum;
    }
};