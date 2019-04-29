class Solution {
    bool close(const string &a, const string &b) {
        int result = 0;
        for (int i = 0, size = a.size(); i < size; i++) {
            if (a[i] != b[i]) {
                if (++result > 1)
                    return false;
            }
        }
        return true;
    }
    
    struct Point {
        const string *word;
        int hops;
        
        Point(const string *w, int h)
            :word(w), hops(h)
        {
        }
    };
    
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        queue<Point> q;
        q.push({&beginWord, 1});
        wordDict.insert(endWord);
        
        vector<const string *> words;
        vector<const string *> words2;
        words.reserve(wordDict.size());
        words2.reserve(wordDict.size());
        for (auto &w:wordDict) {
            words.push_back(&w);
        }
        
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            if (endWord == *p.word) {
                return p.hops;
            }
            
            words2.clear();
            for (int i = 0, size = words.size(); i < size; i++) {
                const string *w = words[i];
                if (close(*w, *p.word)) {
                    q.push({w, p.hops + 1});
                } else {
                    words2.push_back(w);
                }
            }   
            swap(words, words2);
        }
        return 0;
    }
};