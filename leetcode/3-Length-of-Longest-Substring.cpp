/*
3. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
        Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

/*
APPROACH 4
O(1) space, O(n) time, fastest since only 1 pass
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int subLen = 0, slow = 0, fast = 0, sSize = s.size();
        int index[256] = {}; //default zero
        
        while(fast < sSize){
            //if s[fast] has been seen more recently than s[slow], advance slow ptr to the char right-adjacent to the previous occurence of s[fast]
            slow = max(index[s[fast]], slow);
            subLen = max(subLen, fast - slow + 1);
            //store index of char right-adjacent to s[fast]
            index[s[fast]] = fast + 1;
            fast++;
        }
        
        return subLen;
    }
};

/*
APPROACH 3
O(1) space, O(n) time, faster since only using primitive types, but still 2n

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSubLen = 0, currSubLen = 0, slow = 0, fast = 0;
        int sSize = s.size();
        bool seen[256];
        for (int i = 0; i < 256; i++)
            seen[i] = false;
        
        //loop increments fast until all n characters have been iterated over - can only occur a maximum of n times
        while(fast < sSize){
            if (seen[s[fast]]){
                maxSubLen = max(maxSubLen, currSubLen);
                //nested loop increments slow which is always <= fast, so can only occur a maximum of n times
                while(seen[s[fast]]){
                    seen[s[slow]] = false;
                    slow++;
                }
            }
            seen[s[fast]] = true;
            fast++;
            currSubLen = fast - slow;
        }
        maxSubLen = max(maxSubLen, currSubLen);
        
        return maxSubLen;
    }
};

APPROACH 2
O(1) space, O(n^2) time

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSubLen = 0, currSubLen = 0, slow = 0, fast = 0;
        int sSize = s.size();
        unordered_set<char> seen;
        
        while(fast < sSize){
            if (seen.find(s[fast]) != seen.end()){
                maxSubLen = max(maxSubLen, currSubLen);
                while(seen.find(s[fast]) != seen.end()){
                    seen.erase(s[slow]);
                    slow++;
                }
            }
            seen.insert(s[fast]);
            fast++;
            currSubLen = fast - slow;
            //cout << s.substr(slow, currSubLen) << endl;
        }
        maxSubLen = max(maxSubLen, currSubLen);
        
        return maxSubLen;
    }
};

APPROACH 1
O(n) space, O(n^2) time
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSubLen = 0, currSubLen, currPos = 0, runner;
        int sSize = s.size();
        unordered_set<char> seen;
        
        while(currPos < sSize){ //possible optimization || sSize - slow < maxSubLen
            runner = currPos;
            currSubLen = 0;
            while(runner < sSize){
                if (seen.find(s[runner]) != seen.end()){
                    seen.clear();
                    break;
                }
                else{
                    currSubLen++;
                    seen.insert(s[runner]);
                }
                runner++;
            }
            if (maxSubLen < currSubLen)
                maxSubLen = currSubLen;
            //else don't change it
            currPos++;
        }
        return maxSubLen;
    }
};
*/