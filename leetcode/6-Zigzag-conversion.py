'''
6. ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
'''

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s
        
        slen = len(s)
        res = [None]*slen
        curr = 0
        for i in range(numRows):
            j = i
            while j < slen:
                res[curr] = s[j]
                curr += 1
                next_col = 2*(numRows - 1)
                if i != 0 and i != numRows-1:
                    diagonal = j + next_col - 2 * i
                    if diagonal < slen:
                        res[curr] = s[diagonal]
                        curr += 1
                j += next_col
        return "".join(res)


# second solution
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s
        
        slen = len(s)
        rows = [[] for i in range(numRows)]
        
        i = 0
        while i < slen:
            j = 0
            while j < numRows and i < slen:
                rows[j].append(s[i])
                i += 1
                j += 1
            j = numRows - 2
            while j > 0 and i < slen: # all rows except first and last
                rows[j].append(s[i])
                i += 1
                j -= 1
        
        return "".join(["".join(row) for row in rows])
