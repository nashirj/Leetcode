/**
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.
*/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int total_shift = 0;
        for (int i = 0; i < shift.size(); i++) {
            if (shift[i][0] == 1) {
                total_shift += shift[i][1];
            } else {
                total_shift -= shift[i][1];
            }
        }
        
        // total_shift < 0 means left shift
        bool left_shift = (total_shift < 0);
        total_shift = abs(total_shift) % s.size();
        if (left_shift) {
            s = s.substr(total_shift, s.size()) + s.substr(0, total_shift);
        } else {
            s = s.substr(s.size()-total_shift, s.size()) + s.substr(0, s.size()-total_shift);
        }
        
        
        return s;
    }
};