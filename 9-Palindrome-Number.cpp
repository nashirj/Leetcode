/*
9. Palindrome Number

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true

Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up:
Could you solve it without converting the integer to a string?
*/


/**
 * actually reverse the number by modulusing and reducing original number, compare at end to determine validity
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int num = x;
        long reversed = 0;
        
        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return reversed == x;
    }
};

/**
 * Use vector of ints, compare moving inward from both sides
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        vector<int> nums;
        int iter = x;
        while (iter > 0) {
            nums.push_back(iter % 10);
            iter /= 10;
        }
        int numsize = nums.size();
        for (int i = 0; i < numsize / 2; i++){
            if (nums[i] != nums[numsize-i-1])
                return false;
        }
        return true;
    }
};

/**
 * Convert to string, compare moving inward from both sides
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string s = to_string(x);
        int slen = s.size();
        for (int i = 0; i < slen / 2; i++){
            if (s[i] != s[slen-i-1])
                return false;
        }
        return true;
    }
};