class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int current = nums[0];
        int count = 1;
        
        for (int  i = 1, size = nums.size(); i < size; i++) {
            if (current == nums[i]) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    current = nums[i];
                    count = 1;
                }
            } 
            
        }
        
        return current;
    }
};