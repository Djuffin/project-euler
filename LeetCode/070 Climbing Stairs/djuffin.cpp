class Solution {
public:
    int climbStairs(int n) {
        int skip1 = 1, skip2 = 0;
        int current = 0;
        for (int i = 0; i < n; i++) {
            current = skip1 + skip2;
            skip2 = skip1;
            skip1 = current;
        }
        return current;
        
    }
};