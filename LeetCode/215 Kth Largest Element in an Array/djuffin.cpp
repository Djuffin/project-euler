class Solution {
    pair<int *, int *> partition(int* begin, int *end) {
        int *left = begin;
        int *right = begin + 1;
        int *cursor = begin + 1;
        int target = *left;
        
        while (cursor < end) {
            if (*cursor < target) {
                swap(*left, *cursor);
                left++;
                swap(*right, *cursor);
                right++;
            } else if (*cursor == target) {
                swap(*right, *cursor);
                right++;
            }
            cursor++;
        }
        
        return pair<int*, int*>(left, right);
    }
    
    int *find(int *begin, int *end, int k) {
        while (begin < end) {
            if (k >= (end - begin)) {
                break;
            }
            
            if (end - begin == 1) {
                return begin;
            }
            
            auto mid = partition(begin, end);
            int count_less = mid.first - begin;
            int count_eq = mid.second - begin;
            if (count_less > k) {
                end = mid.first;
            } else if (count_eq > k) {
                return mid.first;
            } else {
                begin = mid.second;
                k -= count_eq;
            }
        }
        return nullptr;
    }
    
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int *result = find(&*nums.begin(), &*nums.end(), nums.size() - k);
        if (result == nullptr) return 999;
        return *result;
    }
};