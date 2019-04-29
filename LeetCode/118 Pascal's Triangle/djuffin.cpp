class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return vector<vector<int>>();
        vector<vector<int>> result(numRows);
        
        result[0].push_back(1);
        for (int row = 1; row < numRows; row++) {
            result[row].resize(row + 1);
            for (int i = 0; i <= row; i++) {
                int sum = 0;
                if (i > 0) {
                    sum += result[row - 1][i - 1];
                }
                if (i < row) {
                    sum += result[row - 1][i];
                }
                result[row][i] = sum;
            }
        }
        return result;
    }
};