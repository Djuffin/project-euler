class Solution {
    uint8_t *sieve;
    
    void set(int n) {
        sieve[n >> 3] |= (1 << (n & 7));
    }
    
    bool get(int n) {
        return (sieve[n >> 3] & (1 << (n & 7))) != 0;
    }
    
public:
    int countPrimes(int n) {
        size_t size = n / 8 + 2;
        sieve = new uint8_t[size];
        memset(sieve, 0, size);
        int result = 0;
        
        for (int i = 2; i < n; i++) {
            if (!get(i))  {
                result++;
                for (int j = i; j < n; j += i) {
                    set(j);
                }
            }
        }
        
        return result;
    }
};