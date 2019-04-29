class Solution {
public:
    int maxArea(vector<int>& height) {
        auto right = height.end() - 1;
        auto left = height.begin();
        
        int best_area = 0;
        while (left < right) {
            int area = (right - left) * min(*left, *right);
            if (best_area < area) {
                best_area = area;
            }
            
            if (*left < *right) {
                left++;
            } else {
                right--;
            }
        }
        
        return best_area;
        
    }
};