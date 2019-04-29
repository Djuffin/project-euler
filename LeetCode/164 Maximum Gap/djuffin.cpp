class Solution {
    int key(int x, int i) {
        return 0xff & (x >> (8 * i));
    }
    
    void radixSort(vector<int>& nums) {
        int counting[257];
        vector<int> buffer(nums.size());
        
        for (int iteration = 0; iteration < 4; iteration++) {
            for (int i = 0; i < 257; i++) {
                counting[i] = 0;
            }
            
            for (int v : nums) {
                counting[key(v, iteration) + 1]++;
            }
        
            for (int i = 1; i < 257; i++) {
                counting[i] += counting[i - 1];
            }
            
            for (int v : nums) {
                buffer[counting[key(v, iteration)]++] = v;
            }
            
            nums.swap(buffer);
        }
    }
    
    
public:
    int maximumGap(vector<int>& nums) {
        radixSort(nums);
        int max_gap = 0;
        for (int i = 1; i < nums.size(); i++) {
            int gap = nums[i] - nums[i - 1];
            max_gap = max(max_gap, gap);
        }
        return max_gap;
        
    }
};