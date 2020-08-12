'''
68. Text Justification
Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:
    A word is defined as a character sequence consisting of non-space characters only.
    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    The input array words contains at least one word.

Example 1:
Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:
Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.

Example 3:
Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
'''

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        curr_line_len = 0
        words_on_line = 0
        
        curr_word = 0
        num_words = len(words)
        
        lines = []
        while curr_word < num_words:
            word = words[curr_word]
            # need to be able add space to the end of the line
            curr_line_len += len(word)
            if curr_line_len <= maxWidth:
                curr_line_len += 1 # need at least one space between adjacent words
                words_on_line += 1
                curr_word += 1
            else:
                curr_line_len -= len(word)
                # create line here? need to handle case of last line tho
                lines.append(self.create_line(words, words_on_line, curr_word, maxWidth, last_line=False))
                words_on_line = 0
                curr_line_len = 0
        #construct last line
        lines.append(self.create_line(words, words_on_line, curr_word, maxWidth, last_line=True))
        return lines
        
    def create_line(self, words, words_on_line, curr_word, max_width, last_line=False):
        curr_line = words[curr_word-words_on_line:curr_word]
        num_words = len(curr_line)
        
        if last_line or num_words == 1:
            # this handles last line or case with one word s.t. len(word) < max_width
            line = " ".join(curr_line)
            extra_spaces = max_width - len(line)
            line += " " * extra_spaces
        else:
            # case 1, equally spaced
            # case 2, >2 words with num_spaces % num_words != 0
            num_spaces = max_width - sum([len(word) for word in curr_line])
            spaces_per_word = num_spaces // (num_words - 1)
            extra_spaces = num_spaces - spaces_per_word * (num_words - 1)
            if extra_spaces:
                print(extra_spaces)
                line = ""
                curr = 0
                for i in range(extra_spaces):
                    line += curr_line[curr] + " " * (spaces_per_word + 1)
                    curr += 1
                while curr < num_words-1:
                    line += curr_line[curr] + " " * (spaces_per_word)
                    curr += 1
                line += curr_line[-1]
            else:
                spaces = " " * spaces_per_word
                line = spaces.join(curr_line)
        
        return line
        