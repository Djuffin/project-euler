class Solution {
    int rob1(vector<int>& nums) {
        int max_loot = 0;
        int skip_one = 0;
        int skip_two = 0;
        int current = 0;
        
        for (int i = 0, size = nums.size(); i < size; i++) {
            int loot = nums[i] + max(skip_one, skip_two);
            skip_two = skip_one;
            skip_one = current;
            current = loot;
            if (current > max_loot) {
                max_loot = current;
            }
        }
        
        return max_loot;
        
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } 
        if (nums.size() == 0) {
            return 0;
        }
        auto a = nums;
        a[0] = 0;
        auto b = nums;
        b[b.size() - 1] = 0;
        
        return max(rob1(a), rob1(b));
        
    }
};