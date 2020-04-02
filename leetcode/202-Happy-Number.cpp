/**
202. Happy Number

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

*/


class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        while (true) {
            // Floyd's cycle detection algo to find a cycle if there is one
            fast = happify(fast);
            fast = happify(fast);
            slow = happify(slow);
            if (fast == 1) {
                return true;
            }
            if (fast == slow) {
                return false;
            }
        }
    }
    int happify(int n) {
        int res = 0;
        while (n > 0) {
            res += (n%10)*(n%10);
            n /= 10;
        }
        return res;
    }
};


class Solution {
public:
    bool isHappy(int n) {
        int res = 0;
        set<int> visited;
        while (true) {
            while (n > 0) {
                res += (n%10)*(n%10);
                n /= 10;
            }
            if (res == 1) {
                return true;
            }
            if (visited.find(res) != visited.end()) {
                return false;
            }
            visited.insert(res);
            n = res;
            res = 0;
        }
    }
};