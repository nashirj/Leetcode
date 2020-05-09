/**
367. Valid Perfect Square
Given a positive integer num, write a function which returns
    True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Output: true

Example 2:
Input: 14
Output: false
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        // a perfect square is of the form \sum_{k=0} (2k + 1), i.e.
        // 1 = 1, 1 + 3 = 4, 1 + 3 + 5 = 9, etc...
        if (num < 0) {
            return false;
        }
        long res = 0;
        for (int i = 1; res < num; i += 2) {
            res += i;
        }
        return res == num;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) {
            return false;
        }
        int l = 0, r = num/2;
        unsigned long mid = l + (r - l)/2;
        while (l <= r) {
            mid = l + (r - l)/2;
            if (mid*mid < num) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        mid = l; // with l <= r loop, l points to desired value after loop termination
        return mid*mid == num;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) {
            return false;
        }
        unsigned long temp = num/2;
        while (temp*temp > num) {
            temp /= 2;
        }
        while (temp*temp < num) {
            temp++;
        }
        return temp*temp == num;
    }
};