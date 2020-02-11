//804. Unique Morse Code Words
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if (words.size() == 0)
            return 0;
        else if (words.size() == 1)
            return 1;
        
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> uniqueWords;
        size_t num_words = words.size();
        
        for(int i = 0; i < num_words; i++){
            string word = "";   
            for(char& c : words[i]){
                word += morse[c-'a']; //I used a map at first, see below, then revised solution after seeing examples of other people's approach
            }
            uniqueWords.insert(word); //if duplicate, it won't insert
        }
        
        return uniqueWords.size();
    }
};

//FIRST SOLUTION
/*
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if (words.size() == 0)
            return 0;
        else if (words.size() == 1)
            return 1;
        
        map<char, string> abc_to_morse;
        string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        //input will only be lowercase letters, don't need to worry about uppercase/punctuation
        int alphabet = 26;
        for (int i = 0; i < alphabet; i++){
            abc_to_morse[char('a' + i)] = string(morse[i]);
        }
        
        set<string> uniqueWords;
        set<string>::iterator it;
        size_t num_words = words.size();
        
        for(int i = 0; i < num_words; i++){
            string word = "";
            size_t wsize = words[i].length();
            for (int j = 0; j < wsize; j++){
                word += abc_to_morse[words[i][j]];
                //no need to format, input will only be lowercase letters
            }
            if (uniqueWords.find(word) == uniqueWords.end())
                uniqueWords.insert(word);
        }
        
        return uniqueWords.size();
    }
};
*/