/*
50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:
Input: 2.00000, 10
Output: 1024.00000

Example 2:
Input: 2.10000, 3
Output: 9.26100

Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/

class Solution {
public:
    double myPow(double x, int n) {
        // if (x == 0)
        //     return 0;
        if (n == 0)
            return 1;
        else if (n == -2147483648)
            return myPow(x,-2147483647)/x;
        else if (n < 0)
            return 1/(myPow(x, -n));
        
        if (n % 2 == 0) {
            x = myPow(x, n/2);
            return x * x;
        }
        else { //if (n % 2 == 1)
            return x * myPow(x, n-1);
        }
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        double power = 1.0;
        long p = labs(n);  
        while (p) {
            if (p % 2) {
                power *= x;
            }
            x *= x;
            p /= 2;
        }
        return n >= 1 ? power : 1 / power;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        long long ndouble = n;
        return myPow(x, ndouble);
    }
    double myPow(double x, long long n){
        if (n < 0)
            return 1/(myPow(x, -n)); //overflows when n = -2147483648
        else if (n == 0)
            return 1;
        
        if (n % 2 == 0) {
            x = myPow(x, n/2);
            return x * x;
        }
        else { //if (n % 2 == 1)
            return x * myPow(x, n-1);
        }
    }
};