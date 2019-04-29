class Solution {
  public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.empty()) return false;
            
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
        
        return !dp.back().empty();
    }
};