class Solution {
    int replace(int n) {
        int result = 0;
        while (n != 0) {
            int digit = n % 10;
            result += digit * digit;
            n /= 10;
        }
        return result;
    }
    
public:
    bool isHappy(int n) {
        int x;
        unordered_set<int> seen;
        
        for(x = n; x != 1 && seen.find(x) == seen.end(); ) {
            seen.insert(x);
            x = replace(x);
        }
        
        return x == 1;
    }
};