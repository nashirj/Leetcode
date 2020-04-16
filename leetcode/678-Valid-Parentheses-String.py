'''
678. Valid Parenthesis String
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True

Note:
The string size will be in the range [1, 100].
'''

class Solution:
    def checkValidString(self, s: str) -> bool:
        # balance is between left and right parens
        lo = 0
        hi = 0
        # [lo, hi] is range of how many possible unmatched left parentheses there are
        for c in s:
            # want max range between lo and hi, so if possible to decrement lo, do so
            lo += 1 if c == '(' else -1
            # want max range between lo and hi, so if possible to increment hi, do so
            hi += 1 if c != ')' else -1
            # if at any point, we have unmatched right parentheses, we can't balance
            if hi < 0:
                return False
            # lo will only be less than zero due to wildcards, if it was due to
            # too many right parentheses, we'd have already returned false. ignore
            # these extra wildcards
            lo = max(lo, 0)
        
        # if we have unmatched left parentheses, we didn't balance
        return lo == 0