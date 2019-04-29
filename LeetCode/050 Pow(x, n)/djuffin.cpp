class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        double cur = x;
        
        if (n == INT_MIN) {
            return 1.0 / myPow(x, 1 - n) / x;
        }
        
        if (n < 0) {
            return 1.0 / myPow(x, -n);
        }
        
        while (n) {
            if (n % 2 != 0) {
                result *= cur;
            }
            
            cur *= cur;
            n /= 2;
        }
        
        return result;
        
    }
};