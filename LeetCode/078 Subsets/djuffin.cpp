class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        unsigned int total_size = 1 << nums.size(); 
        result.reserve(total_size);
        assert (nums.size() < 32);
        for (unsigned int n = 0; n < total_size; n++) {
            unsigned int i = n;
            int index = 0;
            vector<int> subset;
            subset.reserve(nums.size());
            while (i != 0) {
                if ((i & 1) != 0) {
                    subset.push_back(nums[index]);
                }
                index++;
                i >>= 1;
            }
            result.push_back(subset);
        }
        return result;
        
    }
};