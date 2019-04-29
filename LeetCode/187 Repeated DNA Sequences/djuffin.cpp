class Solution {
    uint32_t convert(const char *s, uint32_t p) {
        uint32_t result = (p == 0xFFFFFF) ? 0 : p;
        int low = (p == 0xFFFFFF) ? 0 : 9;
        
        for (int i = low; i < 10; i++) {
            uint32_t v = 0;
            switch (s[i]) {
                case 'A':
                    v = 0;
                    break;
                case 'C':
                    v = 1;
                    break;
                case 'G':
                    v = 2;
                    break;
                case 'T':
                    v = 3;
                    break;
            }
            
            result <<= 2;
            result |= v;
        }
        result &= 0xFFFFF;
        return result;
    }
    
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return vector<string>();
        uint32_t value = 0xFFFFFF;
        
        vector<string> result;
        vector<uint16_t> map(1 << 20, 0);
        auto substr = &*s.begin();
        for (int i = 0, size = s.size(); i <= size - 10; i++) {
           value = convert(substr, value);
           if (++map[value] == 2) {
               result.push_back(string(substr, 10));
           }
           substr++;
        }
        
        return result;
       
    }
};