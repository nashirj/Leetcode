class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if not s or not p or len(p) > len(s):
            return []
        chars = {}
        for key in p:
            chars[key] = chars.get(key, 0) + 1
        
        p_len = len(p)
        
        # maybe count first p_len characters, then update accordingly
        curr_chars = {}
        for i in range(p_len):
            curr_chars[s[i]] = curr_chars.get(s[i], 0) + 1
        
        num_anagrams = []
        # check for first p_len chars
        if curr_chars == chars:
            num_anagrams.append(0)
                
        left = 1
        right = p_len
        
        while right < len(s):
            curr_chars[s[left-1]] = curr_chars.get(s[left-1], 0) - 1
            if curr_chars[s[left-1]] == 0:
                curr_chars.pop(s[left-1], None)
            curr_chars[s[right]] = curr_chars.get(s[right], 0) + 1
            if curr_chars == chars:
                num_anagrams.append(left)
            left += 1
            right += 1
        return num_anagrams