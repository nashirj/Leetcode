/*
1023. Camelcase Matching
A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.

Example 1:
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".

Example 2:
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: 
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".

Example 3:
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: 
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".

Note:
1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
All strings consists only of lower and upper case English letters.
*/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int queries_size = queries.size();
        vector<bool> ans(queries_size);
        int p_size = pattern.size();
        for (int i = 0; i < queries_size; i++) {
            string query = queries[i];
            int q_size = query.size();
            int p_pos = 0, q_pos = 0;
            while (q_pos < q_size && p_pos < p_size) {
                //handles case where pattern size is 0
                if (query[q_pos] == pattern[p_pos])
                    p_pos++;
                else if (isupper(query[q_pos]))
                    break;
                q_pos++;
            }
            //optimization, can do without, but prevents iterating through q if not necessary
            if (p_pos < p_size) {
                ans[i] = false;
                continue;
            }
            while (q_pos < q_size) {
                if (isupper(query[q_pos]))
                    break;
                q_pos++;
            }
            //if we got here, p_pos == p_size, so no need to check
            ans[i] = (q_pos == q_size);// && p_pos == p_size);
        }
        return ans;
    }
};