class Solution {
    
    int product(int *begin, int *end) {
        int result = 1;
        while (begin != end) {
            result *= *begin;
            begin++;
        }
        
        return result;
    }
    
    int maxProductNoZero(int *begin, int *end) {
        if (end - begin == 1) return *begin;
        int result = product(begin, end);
        if (result >= 0) return result;
        
        int *left = begin;
        int left_product = 1;
        while (*left >= 0) {
            left_product *= *left;
            left++;
        }
        left_product *= *left;
        left++;
        
        int *right = end - 1;
        int right_product = 1;
        while ( *right >= 0) {
            right_product *= *right;
            right--;
        }
        right_product *= *right;
        
        if (abs(right_product) > abs(left_product)) {
            return product(left, end);
        } else {
            return product(begin, right);
        }
    }
    
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int maximum = 0;
        int *begin = &*nums.begin();
        int *end = &*nums.end();
        int *left = begin, *right = begin;
        while (right < end) {
            if (*right == 0) {
                if (right != left) {
                    int product = maxProductNoZero(left, right);
                    maximum = max(max(0, product), maximum);
                }
                right++;
                left = right;
                
            } else {
                right++;
            }
        }
        if (right != left) {
            int product = maxProductNoZero(left, right);
            if (product > maximum) {
                maximum = product;    
            }
        }
        
        return maximum;
    }
};

//Actually there is a simplier solution with DP
// Besides keeping track of the largest product, we also need to keep track of the smallest product. Why? 
// The smallest product, which is the largest in the negative sense could become the maximum when being 
// multiplied by a negative number.
// 
// Let us denote that:
// 
// f(k) = Largest product subarray, from index 0 up to k.
// Similarly,
// 
// g(k) = Smallest product subarray, from index 0 up to k.
// Then,
// 
// f(k) = max( f(k-1) * A[k], A[k], g(k-1) * A[k] )
// g(k) = min( g(k-1) * A[k], A[k], f(k-1) * A[k] )
// There we have a dynamic programming formula. Using two arrays of size n, 
// we could deduce the final answer as f(n-1). Since we only need to access its previous elements at each step, 
// two variables are sufficient.

