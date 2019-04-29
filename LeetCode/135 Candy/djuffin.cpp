class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int candy = 0;
        int sum_candy = 0;
        int max_position = -1;
        int max_limit = -1;
        for (int i = 0; i < ratings.size(); i++) {
            if (i == 0 || ratings[i] == ratings[i - 1]) {
                max_position = i;
                max_limit = -1;
                candy = 1;
            }
            else if (ratings[i] > ratings[i - 1]) {
                max_position = i;
                max_limit = -1;
                candy++;
            }  
            else {
                if (candy > 1) {
                    if (candy > 2) {
                        max_position = i;
                        max_limit = candy - 2;
                    }
                    candy = 1;
                }
                else {
                    candy = 1;
                    sum_candy += (i - max_position);
                    if (max_limit != -1) {
                        max_limit--;
                        if (max_limit == 0) {
                            max_limit = -1;
                            max_position--;
                        }
                    }
                    
                }
                
            }
            sum_candy += candy;
        }
        
        return sum_candy;
    }
};