class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        uint32_t x = n;
        return 0 == (x & (x - 1));
        
    }
};