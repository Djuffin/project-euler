// Twitter phone interview.
// Implement a class with methods:
// void insert(List<String> wordsToInsert)
// List<String> lookup(String key), key - can contain a '.' which means any character
// lookup(".ac.") => ["hack", "back", "sack" ...]
// lookup("b.ll") => ["ball", "bull", ...]

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    bool wordEnd;
    char c;
    Node *parent;
    unordered_map<char, Node *> children;
};


class LookupTable {
    Node root;
    
public:
    LookupTable()
    {
        root.wordEnd = false;
    }

    void insert(vector<string> &words) {
        
        for (auto &word : words) {
            
            Node *currentNode = &root;
            
            for (char c : word) {
                auto it = currentNode->children.find(c);
                if (it == currentNode->children.end()) {
                    auto node = new Node();
                    node->wordEnd = false;
                    node->parent = currentNode;
                    node->c = c;
                    currentNode->children[c] = node;
                    currentNode = node;
                } else {
                    currentNode = it->second;
                }
            }
            
            currentNode->wordEnd = true;
        }
    }
    
    vector<string> lookup(string key) {
        vector<Node *> nodes;
        vector<string> result;
        nodes.push_back(&root);
        
        for (auto c : key) {
            vector<Node *> nextSextNodes;
            for (auto node : nodes) {
                if (c == '.') {
                    
                    for (auto it : node->children) {
                        nextSextNodes.push_back(it.second);
                    }
                        
                } else {
                    auto it = node->children.find(c);
                    if (it != node->children.end()) {
                        nextSextNodes.push_back(it->second);    
                    }
                }
            }
            
            nodes = nextSextNodes;
        }
        
        for (auto node : nodes) {
            string word;
            
            while (node != &root) {
                word.push_back(node->c);
                node = node->parent;
            }
            reverse(word.begin(), word.end());
            result.push_back(word);
        }
        
        return result;
    }
    
};


int main() {
    LookupTable table;
    vector<string> words;
    words.push_back("hello");
    words.push_back("helfo");
    words.push_back("world");
    table.insert(words);
    auto result = table.lookup(".....");
    for (auto &word : result) {
        cout << word;
        cout << "\n";
    }
}