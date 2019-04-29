class Solution {
    
    int *binary_search(int *begin, int *end, int target) {
        int *total_end = end;
        
        while (begin < end) {
            int *mid = begin + (end - begin) / 2;
            if (*mid < target) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        
        if (begin == total_end || *begin != target) {
            return nullptr;
        }
        
        return begin;
    }
    
    int *search(int *begin, int *end, int target) {
        
        if (begin >= end) {
            return nullptr;
        }
        
        if (*(end - 1) >= *begin) {
            return binary_search(begin, end, target);
        } else {
            int *mid = begin + (end - begin) / 2;
            int *result = search(begin, mid, target);
            if (result == nullptr) {
                result = search(mid, end, target);
            }
            return result;
        }
    }
    
public:
    int search(vector<int>& nums, int target) {
        int *result = search(&*nums.begin(), &*nums.end(), target);
        if (result == nullptr) {
            return -1;
        } else {
            return result - &*nums.begin();
        }
        
    }
};