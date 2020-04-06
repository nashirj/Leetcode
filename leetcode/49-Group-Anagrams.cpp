/**
49. Group Anagrams
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
All inputs will be in lowercase.
The order of your output does not matter.
*/

// takeaway: apparently multiset is slow af

//120ms
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        set<string> unique_strs;
        for (string str : strs) {
            string curr = str;
            sort(curr.begin(), curr.end());
            unique_strs.insert(curr);
        }
        
        map<string, int> unique_char_sets; // map each char_set to index in output vector
        vector<vector<string>> res;
        int rsize = 0; // size of output container
        for (int i = 0; i < strs.size(); i++) {
            string curr_sorted = strs[i];
            sort(curr_sorted.begin(), curr_sorted.end());
            if (unique_char_sets.find(curr_sorted) == unique_char_sets.end()) {
                unique_char_sets[curr_sorted] = rsize;
                res.push_back(vector<string>());
                res[rsize++].push_back(strs[i]);
            } else {
                res[unique_char_sets[curr_sorted]].push_back(strs[i]);
            }
        }
        return res;
    }
};

//644ms
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // set<set<char>> unique_char_ sets;
        map<multiset<char>, int> unique_char_sets; // map each char_set to index in output vector
        vector<vector<string>> res;
        int rsize = 0; // size of output container
        for (int i = 0; i < strs.size(); i++) {
            multiset<char> curr_chars;
            for (char c : strs[i]) {
                curr_chars.insert(c);
            }
            if (unique_char_sets.find(curr_chars) == unique_char_sets.end()) {
                unique_char_sets[curr_chars] = rsize;
                res.push_back(vector<string>());
                res[rsize++].push_back(strs[i]);
            } else {
                res[unique_char_sets[curr_chars]].push_back(strs[i]);
            }
        }
        return res;
    }
};