'''
451. Sort Characters By Frequency
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:
Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
'''


class Solution:
    def frequencySort(self, s: str) -> str:
        char_set = collections.Counter(s)
        
        res = ""
        
        for c, freq in sorted(char_set.items(), key=lambda item: item[1], reverse=True):
            res += c*freq
        
        return res




class Solution:
    def frequencySort(self, s: str) -> str:
        char_set = {}
        for c in s:
            if c in char_set:
                char_set[c] += 1
            else:
                char_set[c] = 1
        
        char_set = sorted(char_set.items(), key=lambda elem: elem[1], reverse=True)
        
        res = ""
        for item in char_set:
            res += item[0]*item[1]
        return res
        


class Solution:
    def frequencySort(self, s: str) -> str:
        char_set = {}
        for c in s:
            if c in char_set:
                char_set[c] += 1
            else:
                char_set[c] = 1
        bucket = [[] for i in range(len(s)+1)]
        
        for c, freq in char_set.items():
            bucket[freq].append(c)
            
        res = ""
        i = len(s)
        while i > 0:
            if bucket[i]:
                for c in bucket[i]:
                    res += c*i
            i -= 1
        
        return "".join(res)

