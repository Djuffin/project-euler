class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> prev(triangle.size(), 0);
        vector<int> next(triangle.size(), 0);
        
        
        for (auto &level: triangle) {
            if (level.size() == 1) {
                next[0] = level[0];
            } else {
                for (int i = 0; i < level.size(); i++) {
                    int v = 0;
                    if (i == 0) {
                        v = prev[i]; 
                    } else if (i == level.size() - 1) {
                        v = prev[i - 1];
                    } else {
                        v = min(prev[i], prev[i - 1]);
                    }
                    
                    next[i] = level[i] + v;
                }
            }
            swap(prev, next);
        }
        
        int minimum = prev[0];
        for (int i = 1; i < prev.size(); i++) {
            minimum = min(minimum, prev[i]);
        }
        return minimum;
        
    }
};