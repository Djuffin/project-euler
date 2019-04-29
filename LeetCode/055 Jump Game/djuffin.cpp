class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        
        while (goal > 0) {
            int i = goal - 1;
            while (i >= 0) {
                if (nums[i] + i >= goal) {
                    goal = i;
                    break;
                } 
                if (i == 0) return false;
                i--;
            }
        }
        return true;
        
    }
};