class Solution {
public:
    int strStr(string haystack, string needle) {
        int offsets[256] = {};
        int needle_size = needle.size();
        int hay_size = haystack.size();
        for (int i = 0; i < needle_size; i++) {
            offsets[needle[i]] = needle_size - i - 1;
        }
        
        int start = 0;
        while (start <= hay_size - needle_size) {
            int i;
            for (i = needle_size - 1; i >= 0; i--) {
                if (haystack[start + i] != needle[i]) {
                    break;
                }
            }
            
            if (i < 0) {
                return start;
            } else {
                int offset = offsets[haystack[start + i]] - (needle_size - i - 1);
                start += max(1, offset);
            }
        }
        
        return -1;
    }
};