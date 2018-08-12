/*
888. Uncommon Words from Two Sentences
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]
 

Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.
*/

class Solution {
public:
    vector<string> split(string in, char c = ' ')
    {
        vector<string> result;
        char *str = &in[0];
        
        do{
            char *begin = str;

            while(*str != c && *str)
                str++;

            result.push_back(string(begin, str)); //create a string given two iterators (a range)
        } while (0 != *str++);
        
        return result;
    }
    vector<string> uncommonFromSentences(string A, string B) {
        string C = A + " " + B;
        vector<string> words = split(C, ' ');
        
        map<string, int> uncommon_map;
        
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            if(uncommon_map.find(s) == uncommon_map.end())
                uncommon_map[s] = 1;
            else
                uncommon_map[s] += 1;
        }
        
        vector<string> uncommon_v;
        map<string, int>::iterator it;
        for(it = uncommon_map.begin(); it != uncommon_map.end(); it++){
            if(it->second == 1){
                uncommon_v.push_back(it->first);
            }
        }
        return uncommon_v;
    }
};