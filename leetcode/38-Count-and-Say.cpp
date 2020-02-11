/*
38. Count and Say

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.
*/
        

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string s = "11";
        int i = 2; //algorithm starts at third iteration
        
        while(i < n){
            string curr = "";
            int count = 1;
            int sSize = s.length();
            
            for (int j = 1; j < sSize; j++){
                if (s[j] == s[j-1])
                    count++;
                else{
                    curr += '0' + count;
                    curr += s[j-1];
                    count = 1;
                }
            }
            //since loop exits before last num, append count and last num
            curr += '0' + count;
            curr += s[sSize-1];
                    
            s = curr;
            i++;
        }
        return s;
    }
};