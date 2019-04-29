class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        
        vector<int> output(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            output[i] = product;
            product *= nums[i];
        }
        
        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[i] *= product;
            product *= nums[i];
        }        

        return output;
    }
};