'''
567. Permutation in String
Given two strings s1 and s2, write a function to return true if s2
    contains the permutation of s1. In other words, one of the first
    string's permutations is the substring of the second string.

Example 1:
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
 
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
'''

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if not s1 or not s2 or len(s1) > len(s2):
            return False
        chars = [0]*26
        diff = ord('a')
        
        for c in s1:
            chars[ord(c)-diff] += 1
        
        left, right = 0, 0
        count = s1_len = len(s1)
        
        while right < len(s2):
            if chars[ord(s2[right])-diff] >= 1:
                count -= 1 # one char closer to a match
    
            # we counted the char at position s2[right], so remove from chars
            chars[ord(s2[right])-diff] -= 1
            right += 1
            
            # count == 0 if there are s1_len chars that match consecutively in s2
            # count is decremented only if s2[i] \in s1, so need s1_len consecutive
            if (count == 0):
                return True
            
            # narrow window
            if right - left == s1_len:
                # if char at s2[left] is in s1, increment count
                if chars[ord(s2[left])-diff] >= 0:
                    count += 1
                # the char counted by s2[right] s1_len iterations ago can be used again
                chars[ord(s2[left])-diff] += 1
                left += 1
        
        return False



class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if not s1 or not s2 or len(s1) > len(s2):
            return False
        chars = [0]*26
        diff = ord('a')
        
        s1_len = len(s1)
        for c in s1:
            chars[ord(c)-diff] += 1
        
        # count first p_len characters, then update accordingly
        curr_chars = [0]*26
        for i in range(s1_len):
            curr_chars[ord(s2[i])-diff] += 1
        
        # check for first p_len chars
        if curr_chars == chars:
            return True
                
        left = 1
        right = s1_len
        
        while right < len(s2):
            curr_chars[ord(s2[left-1])-diff] -= 1
            curr_chars[ord(s2[right])-diff] += 1
            if curr_chars == chars:
                return True
            left += 1
            right += 1
        return False