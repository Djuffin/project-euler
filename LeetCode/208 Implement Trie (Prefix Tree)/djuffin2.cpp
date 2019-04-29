class TrieNode {
public:
    TrieNode *childred[27];
    bool end;


    // Initialize your data structure here.
    TrieNode()
        : childred{0}, end(false)
    {
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto current = root;
        for (char c:word) {
            if (!current->childred[c - 'a']) {
                current->childred[c - 'a'] = new TrieNode();
            }
            current = current->childred[c - 'a'];
        }
        current->end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto current = root;
        for (char c:word) {
            current = current->childred[c - 'a'];
            if (!current) {
                return false;    
            } 
        }
        return current->end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        auto current = root;
        for (char c:prefix) {
            current = current->childred[c - 'a'];
            if (!current) {
                return false;    
            } 
        }
        return true;        
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");