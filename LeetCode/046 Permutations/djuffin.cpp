class Solution {
    
    bool my_next_permutation(int *begin, int *end) {
        if (end - begin < 2) return false;
        
        auto border = end - 2;
        for (; border >= begin && *border >= *(border + 1); border--);
        if (border < begin)
            return false;
            
        auto i = end - 1;
        for (; *border >= *i; i--);
        
        swap (*i, *border);
        reverse(border + 1, end);
        return true;
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
     
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        do {
            result.push_back(nums);
        } while (my_next_permutation(&*nums.begin(), &*nums.end()));
        
        return result; 
   
    }
};