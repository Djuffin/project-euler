class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int seen[1000] = {};
        auto left = s.begin();
        auto right = left;
        int len = 0, max_len = 0;
        
        while (right < s.end()) {
            
            if (seen[*right] == 0) {
                seen[*right]++;
                len++;
                right++;
            }
            else {
                seen[*left]--;
                len--;
                left++;
            }
            
            if (max_len < len) {
                max_len = len;
            }
            
        }
        
        return max_len;
        
        
    }
};