class Solution {
    
    vector<string> results;
    
    string format(vector<const string *> path) {
        string result;
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            if (i != 0) result.append(" ");
            result.append(*(path[i]));
        }
        return result;
    }
    
    void collect(vector<vector<const string *>> &dp, vector<const string *> &path, int right) {
        for (auto word : dp[right]) {
            if (word == nullptr) {
                results.push_back(format(path));
                return;
            }
            path.push_back(word);
            collect(dp, path, right - word->size());
            path.pop_back();
        }
    }
    
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.empty()) return results;
            
        size_t min_len = INT_MAX, max_len = 0;
        for (auto &word : wordDict) {
            min_len = min(min_len, word.size());
            max_len = max(max_len, word.size());
        }
        
        vector<vector<const string *>> dp(s.size() + 1);
        dp[0].push_back(nullptr);
        
        for (int left = 0; left < s.size(); left++) {
            if (dp[left].empty()) continue;
            for (int right = left + min_len; right <= min(left + max_len, s.size()); right++) {
                string word = s.substr(left, right - left);
                auto it = wordDict.find(word);
                if (it!= wordDict.end()) {
                    dp[right].push_back(&(*it));
                }
            }
        }
        
        vector<const string *> path;
        collect(dp, path, s.size());

        return results;
    }
};