class Solution {

public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> s;
        int area = 0;
        height.insert(height.begin(), 0);
        height.push_back(0);
        
        for (int i = 0; i < height.size(); i++) {
            while (!s.empty() && height[s.top()] > height[i]) {
                int last = s.top();
                s.pop();
                area = max(area, height[last] * (s.empty() ? i : i - s.top() - 1));
                
            }
            
            s.push(i);
        }
        
        return area;
    }
};