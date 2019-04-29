class Solution {
public:
    int rob(vector<int>& nums) {
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
};