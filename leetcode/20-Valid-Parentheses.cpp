/*
20. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

//O(n) time O(n) space
class Solution {
public:
    bool isValid(string s) {
        //sptr is stack "pointer", slen is length of s
        int sptr = 0, slen = s.length();
        
        //stack of size s;
        vector<char> s_paren(slen);
        
        for(int i = 0; i < slen; i++){
            switch(s[i]){
                case '[':
                case '(':
                case '{':
                    s_paren[sptr] = s[i];
                    sptr++;
                    break;
                case ']':
                    if(sptr > 0 && s_paren[sptr-1] == '[')
                        sptr--;
                    else
                        return false;
                    break;
                case ')':
                    if(sptr > 0 && s_paren[sptr-1] == '(')
                        sptr--;
                    else
                        return false;
                    break;
                case '}':
                    if(sptr > 0 && s_paren[sptr-1] == '{')
                        sptr--;
                    else
                        return false;
                    break;
                default:
                    return false;
            }
        }
        
        return (sptr == 0);
    }
};