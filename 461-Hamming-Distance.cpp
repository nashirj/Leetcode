/*
461. Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note:
0 ≤ x, y < 2^31.

Example:
Input: x = 1, y = 4
Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

/*
APPROACH 3 - found on leetcode, not me
the "while(n)" part is equivalent to while there is a bit set go into the loop
when in the loop the "++dist" just counts how may bits we have turned off(set to 0) so far
the "n &= n-1" turns off(set to 0) the right most 1 bit
when we exit the loop we know that n must be zero and hence dist will contain the number of bits set to one in x^y
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};

/*
//APPROACH 2

#include <bitset>

class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> xset(x);
        bitset<32> yset(y);
        
        int ans = 0;
        
        for(int i = 0; i < 32; i++){
            if (xset[i] ^ yset[i] == 1)
                ans++;
        }
        
        return ans;
        
    }
};

//APPROACH 1

#include <bitset> 
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        
        string xb=bitset<32>(x).to_string();
        string yb=bitset<32>(y).to_string();
        
        for (int i=0;i<32;i++){
            if(xb[i]!=yb[i])
                ans++;
        }
        return ans;
    }
};

*/