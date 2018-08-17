#include <iostream>
#include <string>
using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
        if (words.size() == 0)
            return 0;
        else if (words.size() == 1)
            return 1;
        
        int alphabet = 26;
        string morse[alphabet] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<char, string> abc_to_morse;
        
        //input will only be lowercase letters, don't need to worry about uppercase/punctuation
        for (int i = 0; i < alphabet; i++){
            abc_to_morse[char('a' + i)] = string(morse[i]);
        }
        
        size_t num_words = words.size();
        string arr_of_morse[num_words];
        for(int i = 0; i < num_words; i++){
            string word = "";
            size_t wsize = words[i].length();
            for (int j = 0; j < wsize; j++){
                word += abc_to_morse[words[i][j]]; //no need to format, input will only be lowercase letters
            }
            arr_of_morse[i] = word;
        }
        
        int transformations = 1;
        for (int i = 0; i < num_words; i++){
            int temp_transformations = 1;
            for (int j = i+1; j < num_words; j++){
                if (arr_of_morse[i] == arr_of_morse[j])
                    temp_transformations++;
            }
            transformations = max(transformations, temp_transformations);
        }
        return transformations;
    }

    int main(){
        vector v = ["rwjje","aittjje","auyyn","lqtktn","lmjwn"];
        cout << uniqueMorseRepresentations(v) << endl;
    }