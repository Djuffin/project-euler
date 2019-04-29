class Solution {
public:
    int numTrees(int n) {
        vector<int> results(n + 1);
        results[0] = results[1] = 1;
        results[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                results[i] += results[j] * results[i - j - 1];
            }
        }
        return results[n];
    }
};