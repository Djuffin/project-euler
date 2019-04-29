class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto total_size = nums1.size() + nums2.size();
        if (total_size % 2 == 1) {
            return find_nth(&*nums1.begin(), (int)nums1.size(), &*nums2.begin(), (int)nums2.size(), total_size / 2);
        } else {
            double a = find_nth(&*nums1.begin(), (int)nums1.size(), &*nums2.begin(), (int)nums2.size(), total_size / 2);
            double b = find_nth(&*nums1.begin(), (int)nums1.size(), &*nums2.begin(), (int)nums2.size(), total_size / 2 - 1);
            return (a + b) / 2;
        }
        
    }
    
private:
    int find_nth(int *left, int left_len, int *right, int right_len, int n) {
        
        if (left_len == 0) {
            return right[n];
        } 
        if (right_len == 0) {
            return left[n];
        }
        
        if (left_len == 1 && right_len == 1) {
            if ((n == 0 && left[0] < right[0]) || (n == 1 && right[0] < left[0])) {
                return left[0];
            } else {
                return right[0];
            }
        }
        
        int right_mid_index= right_len / 2;
        int left_mid_index = binary_search(left, left_len, right[right_mid_index]);

        int total_mid_index = right_mid_index + left_mid_index;
        
        if (total_mid_index == n)
            return right[right_mid_index];
            
        if (total_mid_index < n) {
            return find_nth(right + right_mid_index, right_len - right_mid_index, 
                            left + left_mid_index, left_len - left_mid_index, 
                            n - total_mid_index);
        } else {
            return find_nth(right, right_mid_index, 
                            left, left_mid_index, 
                            n);
        }
    }
    
    int binary_search(int *array, int len, int x) {
        int *left  = array;
        int *right = array + len;
        while (left < right) {
            int *mid = left + (right - left) / 2;
            if (*mid < x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int result = left - array;
        return result;
    }
    
};