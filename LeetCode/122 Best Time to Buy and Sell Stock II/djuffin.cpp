class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        int minimum = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (i == prices.size() - 1 || (prices[i] > prices[i + 1] && prices[i] > minimum)) {
                profit += max(0, prices[i] - minimum);
                minimum = prices[i];
            }
            if (minimum > prices[i]) {
                minimum = prices[i];
            }
        }
        
        return profit;
        
    }
};