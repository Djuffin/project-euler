class Solution {
public:
    string minWindow(string s, string t) {
        vector<bool> needed(256);
        vector<int> counts(256);
        int total_count = 0;
        for (auto c : t) {
            needed[c] = true;
            if (++counts[c] == 1) {
                total_count++;
            }
        }
        int min_len = INT_MAX;
        int min_position = -1;
        
        int left = 0, right = 0;
        while (true) {
            if (left < right && total_count == 0) {
                
                if (min_len > (right - left)) {
                    min_len = right - left;
                    min_position = left;
                }
                
                if (needed[s[left]]) {
                    if (++counts[s[left]] == 1) {
                        total_count++;
                    }
                }
                left++;
            } else {
                if (right >= s.size()) break;
                if (needed[s[right]]) {
                    if (--counts[s[right]] == 0) {
                        total_count--;
                    }
                }
                right++;
            }
        }
        if (min_position == -1) return "";
        return s.substr(min_position, min_len);
    }
};