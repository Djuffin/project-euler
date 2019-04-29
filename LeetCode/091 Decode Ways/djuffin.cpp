class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0)
            return 0;
        
        int stable_count = 1;
        int carry_count = 0;
        char prev = 0;
        
        
        for (int i = 0; i < s.size(); i++) {
            
            int old_stable_count = stable_count;
            
            if (prev == '1') {
                stable_count += carry_count;
            }
            if (prev == '2' && s[i] <= '6') {
                stable_count += carry_count;
            }
            
            if (s[i] == '0') {
                stable_count = carry_count;
                carry_count = 0;
            }
            else if (s[i] == '1' || s[i] == '2') {
                carry_count = old_stable_count;
            } else {
                carry_count = 0;
            }
            
            prev = s[i];
        }
        
        return stable_count;
        
    }
};