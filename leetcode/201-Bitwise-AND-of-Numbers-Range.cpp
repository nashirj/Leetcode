/**
201. Bitwise AND of Numbers Range
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:
Input: [5,7]
Output: 4

Example 2:
Input: [0,1]
Output: 0
*/



class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        /**
        last bit of the result of (odd number & even number) is 0.
        when m != n, there is at least one pairing of integers i,j \in [m, n]
            that have different parity (i odd, j even or i even, j odd)
        since there is at least an odd number and an even number in this range,
            the last bit position in the range of bitwise ands is 0
        bitshift m and n right 1 position and repeat this process until m == n.
        */
        if (!m) {
            return 0;
        }
        int num_right_0s = 0;
        while (n > m) {
            n >>= 1;
            m >>= 1;
            num_right_0s++;
        }
        return m << num_right_0s;
    }
};




// first solution
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = INT_MAX;
        
        for (int i = m; i <= n; i++) {
            res &= i;
            if (res == 0 || i == INT_MAX) {
                break;
            }
        }
        
        return res;
    }
};