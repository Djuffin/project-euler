class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int row = 0, column = n - 1;
        while (row < m && column >= 0) {
            int v = matrix[row][column];
            if (v == target) return true;
            if (v > target) {
                column--;
            } else {
                row++;
            }
        }
        return false;
        
    }
};