class Solution {
   
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.resize(rowIndex + 1, 0);
        result[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            int p = 0;
            for (int j = 0; j <= i; j++) {
                int t = result[j];
                result[j] += p;
                p = t;
            }
        }
        return result;
    }
};