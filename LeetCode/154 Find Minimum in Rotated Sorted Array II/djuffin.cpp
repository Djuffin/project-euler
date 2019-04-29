class Solution {
    int findMin(int *left, int *right) {
        if (left == right - 1) return *left;
        if (*left < *(right - 1)) return *left;
        
        if (right - left == 2) {
            return min (*left, *(left + 1));
        }
        
        int *mid = left + (right - left) / 2;
        
        if (*mid == *left && *mid == *(right - 1)) {
            return min (findMin(left, mid), findMin(mid, right));
        }

        if (*mid >= *left) {
            return findMin(mid + 1, right);    
        } else {
            return findMin(left, mid + 1);
        }
    }
public:
    int findMin(vector<int>& nums) {
        return findMin(&*nums.begin(), &*nums.end());
    }
};