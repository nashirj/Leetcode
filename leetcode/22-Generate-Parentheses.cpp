/*
22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res = vector<string>();
        backtrack(res, "", 0, 0, n);
        return res;
    }
    void backtrack(vector<string>& res, string s, int open, int close, int n) {
        if (s.size() == n * 2) {
            res.push_back(s);
        }
        if (close < open) {
            backtrack(res, s + ')', open, close+1, n);
        }
        if (open < n) {
            backtrack(res, s + '(', open+1, close, n);
        }
    }
};
