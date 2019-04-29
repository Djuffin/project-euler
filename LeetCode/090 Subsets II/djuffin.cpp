class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int,int>> counted_set;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                counted_set.back().second++;
            } else {
                counted_set.push_back({nums[i], 1});
            }
        }
        vector<vector<int>> result;
        int total_number = 1;
        for (auto &p: counted_set) {
            total_number *= p.second + 1;
        }
        
        for (int n = 0; n < total_number; n++) {
            int i = n;
            vector<int> subset;
            for (int j = 0, s = counted_set.size(); j < s; j++) {
                int cnt = counted_set[j].second + 1;
                for (int k = 0; k < i % cnt; k++) {
                    subset.push_back(counted_set[j].first);
                }
                i /= cnt;
            }
            result.push_back(subset);
        }
        
        return result;
    }
};