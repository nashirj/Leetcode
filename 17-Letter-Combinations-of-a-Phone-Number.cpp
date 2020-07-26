/*
17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        vector<string> res = vector<string>();
        if (!len)
            return res;
        map<char, string> mapping = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backtrack(res, mapping, digits, 0, "", len);
        return res;
    };
    void backtrack(vector<string>& res, map<char, string>& mapping, string digits, int pos, string s, int len) {
        if (s.size() == len) {
            res.push_back(s);
            return;
        }
        for (char c : mapping[digits[pos]]) {
            backtrack(res, mapping, digits, pos+1, s + c, len);
        }
    }
};