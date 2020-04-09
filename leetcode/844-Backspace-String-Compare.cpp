/**
844. Backspace String Compare
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

// everything in one loop! this is crazy
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int s_ptr = S.size()-1;
        int s_skip = 0;
        int t_ptr = T.size()-1;
        int t_skip = 0;
        
        while (s_ptr >= 0 || t_ptr >= 0) {
            while (s_ptr >= 0) {
                if (S[s_ptr] == '#') {
                    s_skip++;
                    s_ptr--;
                } else if (s_skip) {
                    s_skip--;
                    s_ptr--;
                } else {
                    break;
                }
            }
            while (t_ptr >= 0) {
                if (T[t_ptr] == '#') {
                    t_skip++;
                    t_ptr--;
                } else if (t_skip) {
                    t_skip--;
                    t_ptr--;
                } else {
                    break;
                }
            }
            if (s_ptr >= 0 && t_ptr >= 0) {
                if (S[s_ptr] != T[t_ptr]) {
                    return false;
                }
            }
            if ((s_ptr >= 0) != (t_ptr >= 0)) {
                return false;
            }
            s_ptr--;
            t_ptr--;
        }
        
        return true;
    }
};




class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int s_size = S.size();
        int s_ptr = s_size-1;
        int s_skip = 0;
        int t_size = T.size();
        int t_ptr = t_size-1;
        int t_skip = 0;
        
        while (s_ptr >= 0 && t_ptr >= 0) {
            if (S[s_ptr] == '#') {
                s_skip++;
                s_ptr--;
            } else if (T[t_ptr] == '#') {
                t_skip++;
                t_ptr--;
            } else if (s_skip) {
                s_skip--;
                s_ptr--;
            } else if (t_skip) {
                t_skip--;
                t_ptr--;
            } else if (S[s_ptr--] != T[t_ptr--]) {
                return false;
            }
        }
        
        while (s_ptr >= 0) {
            if (S[s_ptr] == '#') {
                s_skip++;
                s_ptr--;
            } else if (s_skip) {
                s_skip--;
                s_ptr--;
            } else {
                // if there are chars that are not deleted
                return false;
            }
            
        }
        
        while (t_ptr >= 0) {
            if (T[t_ptr] == '#') {
                t_skip++;
                t_ptr--;
            } else if (t_skip) {
                t_skip--;
                t_ptr--;
            } else {
                // if there are chars that are not deleted
                return false;
            }
        }
        
        return true;
    }
};


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s_stack;
        stack<char> t_stack;
        
        for (char c : S) {
            if (c == '#') {
                if (!s_stack.empty()) {
                    s_stack.pop();
                }
            } else {
                s_stack.push(c);
            }
        }
        for (char c : T) {
            if (c == '#') {
                if (!t_stack.empty()) {
                    t_stack.pop();
                }
            } else {
                t_stack.push(c);
            }
        }
        
        while (!s_stack.empty() && !t_stack.empty()) {
            if (s_stack.top() != t_stack.top()) {
                return false;
            }
            s_stack.pop();
            t_stack.pop();
        }
        
        return (s_stack.empty() && t_stack.empty());
    }
};