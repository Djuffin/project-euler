class Solution {
    
    
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> queue;
        vector<int> result;
        
        for (int i = 0; i < k - 1; i++) {
            while (!queue.empty() && nums[queue.back()] <= nums[i] )
                queue.pop_back();
                
            queue.push_back(i);
        }
        
        for (int i = k - 1; i < nums.size(); i++) {
            while (!queue.empty() && nums[queue.back()] <= nums[i] )
                queue.pop_back();
                
            queue.push_back(i);
            
            int left_side = i - k + 1;
            
            while (!queue.empty() && queue.front() < left_side )
                queue.pop_front();
                
            result.push_back(nums[queue.front()]);
        }
        
        return result;
        
    }
};