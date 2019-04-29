class Solution {
public:
    int trap(vector<int>& height) {
        int max_left = 0, max_right = 0;
        vector<int> volumes;
        
        for (int h : height) {
            if (h > max_left) {
                max_left = h;
                volumes.push_back(0);
            } else {
                volumes.push_back(max_left - h);
            }
            
        }
        for (int i = height.size() - 1; i >= 0; i--) {
            int h = height[i];
            if (h > max_right) {
                max_right = h;
                volumes[i] = 0;
            } else {
                volumes[i] = min(volumes[i], max_right - h);
            }
        }
        int result = 0;
        
        for (int v : volumes) {
            result += v;
        }
        
        return result;
    }
};