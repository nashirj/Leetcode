/*
70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        int base1 = 1, base2 = 2, ans = 0, i = 3;
        while (i <= n){
            ans = base1 + base2;
            base1 = base2;
            base2 = ans;
            i++;
        }
        return ans;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        int a = 1, b = 2, c = 0;
        for (int i = 3; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        int data[n + 1] = {0,1,2};        
        for (int i = 3; i <= n; i++){
            data[i] = data[i-1] + data[i-2];
        }
        return data[n];
    }
};

/**
 * Recursive solution is too slow
 */