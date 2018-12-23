/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

/*
Approach 1
        //check that all N words match at ith index for every letter (assume on average M letters), concatenation is linear in length of new string (on average, M/2) time, so O(N*M*M)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int numWords = strs.size();
        if (numWords == 0)
            return "";
        
        string s = "";
        int wordSize = strs[0].size(); //doesn't matter which word is picked, all must have same prefix
        
        for (int i = 0; i < wordSize; i++){
            for (int j = 1; j < numWords; j++){
                if (strs[0][i] != strs[j][i])
                    return s;
            }
            s.append(1, strs[0][i]);
        }
        
        return s;
        
    }
};


/*
Approach 2
        //check that all N words match at ith index for every letter (assume on average M letters) so O(N*M)
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int numWords = strs.size();
        if (numWords == 0)
            return "";
        if (numWords == 1)
            return strs[0];
        
        int wordSize = strs[0].size(); //doesn't matter which word is picked, all must have same prefix
        for (int i = 0; i < wordSize; i++){
            for (int j = 1; j < numWords; j++){
                if (i == strs[j].size() || strs[0][i] != strs[j][i])
                    return strs[0].substr(0, i); //returns substring from [0, i-1] indices of strs[0]
            }
        }
        
        return strs[0];
        
    }
};