class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        for (int i = 0; i < gas.size(); i++) {
            gas[i] -= cost[i];
        }
        
        int sum = 0, minSum = gas[0];
        for (int i = 0; i < gas.size(); i++) {
            sum += gas[i];
            if (sum < minSum) {
                minSum = sum;
            }
        }
        
        if (minSum >= 0) {
                return 0;
        }
        
        for (int i = gas.size() - 1; i >= 0; i--) {
            if (minSum >= 0) {
                return (i + 1) % gas.size();
            }
            
            minSum += gas[i];
        }
        
        return -1;

    }
};