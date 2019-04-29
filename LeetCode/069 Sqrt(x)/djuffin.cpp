class Solution {
public:
    int mySqrt(int x) {
        double guess = x / 2.0;
        
        while (abs(guess * guess - x) > 0.1) {
            guess = (guess + x / guess) / 2.0;
        }
        
        return (int)guess;
    }
};