class Solution {

    int64_t gcd(int64_t a, int64_t b) {
        if (b == 0) {
            return a;    
        }
        return gcd(b, a % b);
    }
    
    int64_t lcm(int64_t a, int64_t b) {
        return a * b / gcd(a, b);
    }

public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0) return;
        
        int cycle_len = lcm(n, k) / k;
        for (int i = 0; i < n / cycle_len; i++) {
            int val = nums[i];
            
            for (int j = i + k; j != i; j = (j + k) % n) {
                swap(val, nums[j]);
            }
            
            nums[i] = val;
        }
    }
};