class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int best_match = nums[0] + nums[1] + nums[2];
        
        sort (nums.begin(), nums.end());
        for (int base = 0, size = nums.size(); base < size - 2; base++) {
            int left = base + 1;
            int right = size - 1;
            
            while (left < right) {
                int sum = nums[base] + nums[left] + nums[right];
                if (abs(sum - target) < abs(best_match - target)) {
                    best_match = sum;
                }
                
                if (sum > target) {
                    right--;    
                } 
                else if (sum < target) {
                    left++;
                }
                else {
                    return sum;
                }
                
            }
        }
        
        return best_match;
        
        
        
    }
};