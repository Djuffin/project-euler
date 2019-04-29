class Solution {
    
    void traverse(vector<vector<int>> &result, vector<int> &subset, int *begin, int *end, int target) {
        if (target == 0) {
            result.push_back(subset);
            return;
        }
        if (begin == end || target < 0) {
            return;
        }
        subset.push_back(*begin);
        traverse(result, subset, begin, end, target - *begin);
        subset.pop_back();
        traverse(result, subset, begin + 1, end, target);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        auto newend = unique(candidates.begin(), candidates.end());
        vector<int> subset;
        vector<vector<int>> result;
        traverse(result, subset, &*candidates.begin(), &*newend, target);
        return result;
        
    }
};