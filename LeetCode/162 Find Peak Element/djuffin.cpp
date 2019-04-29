class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        
        auto left = &*nums.begin();
        auto right = &*nums.end();
        auto start = left;
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (*mid > *(mid - 1) && *mid > *(mid + 1)) {
                return mid - start;
            }
            if (*mid > *(mid - 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
            
        }
        return left - start;
    }
};