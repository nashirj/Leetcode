/*
461. Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

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