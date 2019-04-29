class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        int minimum = prices[0];
        int profit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (minimum > prices[i]) {
                minimum = prices[i];
            }
            profit = max(profit, prices[i] - minimum);    
        }
        
        return profit;
        
    }
};