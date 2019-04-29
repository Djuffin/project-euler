class Solution {

    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int area = 0;
        height.push_back(0);
        
        for (int i = 0; i < height.size(); i++) {
            while (!s.empty() && height[s.top()] > height[i]) {
                int last = s.top();
                s.pop();
                area = max(area, height[last] * (s.empty() ? i : i - s.top() - 1));
                
            }
            
            s.push(i);
        }
        height.pop_back();
        return area;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<int> counts(m);
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') 
                    counts[j]++;
                else
                    counts[j] = 0;
            }
            area = max(area, largestRectangleArea(counts));
        }
        return area;
    }
};