

class Solution {
    

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (auto a = nums.begin(); a < nums.end();) {
            auto b = a + 1;
            auto c = nums.end() - 1;
            while (b < c) {
                int v =  *a + *b + *c;
                if (v == 0) {
                    vector<int> triplet;
                    triplet.push_back(*a);
                    triplet.push_back(*b);
                    triplet.push_back(*c);
                    result.push_back(triplet);
                    
                    int bv = *b;
                    while (b < c && *b == bv) b++;
                } else if (v > 0) { 
                    c--;
                } else {
                    b++;
                }
            }
            
            int av = *a;
            while (a < nums.end() && *a == av) a++;
        }

        return result;
        
        
    }
};