/*
191. Number of 1 Bits
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: 11
Output: 3
Explanation: Integer 11 has binary representation 00000000000000000000000000001011 
Example 2:

Input: 128
Output: 1
Explanation: Integer 128 has binary representation 00000000000000000000000010000000
*/

//O(logn) time O(1) space
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int weight = 0;
        while (n > 0){
            if(n & 1)
                weight++;
            n >>= 1;
        }
        return weight;
    }
};


//O(logn) time O(logn) space
class Solution {
public:
    int hammingWeight(uint32_t n) {
        string nbit = bitset<32>(n).to_string();
        int weight = 0;
        for (int i = 0; i < 32; i++){
            if(nbit[i] == '1')
                weight++;
        }
        return weight;
    }
};