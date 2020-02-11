/*
344. Reverse String
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/


class Solution {
public:
    void reverseString(vector<char>& s) {
        reverseString(s, 0, s.size() - 1);
    }
    void reverseString(vector<char>& s, int start, int end){
        if (end - start < 1)
            return;
        swap(s[start], s[end]);
        reverseString(s, start + 1, end - 1);
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right){
            swap(s[left++], s[right--]);
        }
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int sLen = s.size();
        char temp;
        
        for (int i = 0; i < sLen / 2; i++){
            temp = s[i];
            s[i] = s[sLen - i - 1];
            s[sLen - i - 1] = temp;
        }
    }
};