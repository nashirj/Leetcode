/**
208. Implement Trie (Prefix Tree)
Implement a trie with insert, search, and startsWith methods.

Example:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

Note:
You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

struct TrieNode {
    /**
    instead of a map, can use a vector, but that scales much worse
    worst case space complexity of O(alphabet^(num_words*average_word_len))
    */
    map<char, TrieNode*> children;
    bool is_end_of_word;
    TrieNode() : children(map<char, TrieNode*>()), is_end_of_word(false) {}
    bool hasChild(char c) {
        return children.find(c-'a') != children.end();
    }
    TrieNode* getChild(char c) {
        // this will break if child is not in Trie
        return children.find(c-'a')->second;
    }
    void addChild(char c, TrieNode* node) {
        children[c-'a'] = node;
    }
};

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        // root is an empty TrieNode*
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* prev = root;
        for (char c : word) {
            if (!prev->hasChild(c)) {
                prev->addChild(c, new TrieNode());
            }
            prev = prev->getChild(c);
        }
        prev->is_end_of_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, true);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, false);
    }
    
    bool find(string s, bool check_end) {
        TrieNode* prev = root;
        
        for (int i = 0; i < s.size(); i++) {
            if (!prev->hasChild(s[i])) {
                return false;
            }
            prev = prev->getChild(s[i]);
        }
        return (check_end) ? prev->is_end_of_word : true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */