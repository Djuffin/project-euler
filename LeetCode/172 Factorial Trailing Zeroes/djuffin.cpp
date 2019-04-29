class Solution {
public:
    int trailingZeroes(int n) {
        int fives = 0;
        for (int64_t power = 5; power <= n; power *= 5) {
            fives += ((int64_t)n) / power;
        }
        
        return fives;
    }
};