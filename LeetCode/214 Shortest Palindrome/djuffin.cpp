class Solution {
    bool isPalindrome(char *begin, char *end) {
        if (begin == end) return true;
        end--;
        while (begin < end) {
            if (*begin != *end)
                return false;
            begin++;
            end--;
        }
        return true;
    }
    
public:
    string shortestPalindrome(string s) {
        int border = 0;
        for (int i = s.size(); i > 0; i--) {
            if (isPalindrome(&s[0], (&s[0]) + i)) {
                border = i;
                break;
            }
        }
        
        if (s.size() == border) {
            return s;
        }
        
        string result = s.substr(border);
        reverse(result.begin(), result.end());
        result.append(s);
        return result;
    }
};