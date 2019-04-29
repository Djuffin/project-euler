class TrieNode {
public:
    char pivot;
    bool end;
    TrieNode *left, *right, *next;

    // Initialize your data structure here.
    TrieNode(char c = 0)
        : pivot{c}, end(false), left(nullptr), right(nullptr), next(nullptr)
    {
    }
};

class Trie {
    
    TrieNode *insertNode(string &word, int index, TrieNode *node) {
        const char c = word[index];
        if (node == nullptr) {
            node = new TrieNode(c);
        }
        if (node->pivot == c) {
            if (index == word.size() - 1) {
                node->end = true;
            } else {
                node->next = insertNode(word, index + 1, node->next);
            }
        } else {
            if (node->pivot > c) {
                node->left = insertNode(word, index, node->left);
            } else {
                node->right = insertNode(word, index, node->right);
            }
        }
        return node;
    }
    
    TrieNode *search(string &word, int index, TrieNode *node) {
        const char c = word[index];
        if (node == nullptr) {
            return nullptr;
        }
        if (node->pivot == c) {
            if (index == word.size() - 1) {
                return node;
            } else {
                return search(word, index + 1, node->next);
            }
        } else {
            if (node->pivot > c) {
                return search(word, index, node->left);
            } else {
                return search(word, index, node->right);
            }
        }
    }

public:
    Trie() {
        root = nullptr;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if (word.empty()) {
            root->end = true;
        } else {
            root = insertNode(word, 0, root);
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if (word.empty()) {
            return root->end;
        } else {
            auto node = search(word, 0, root);
            return node != nullptr && node->end;
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if (prefix.empty()) {
            return true;
        } else {
            auto node = search(prefix, 0, root);
            return node != nullptr;
        }    
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");