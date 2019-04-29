class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        int top = n - 1;
        for (int i = 0; i < n / 2; i++, top--) {
            for (int j = i; j < top; j++) {
                
                int i1 = j, j1 = n - 1 - i;
                swap(matrix[i][j], matrix[i1][j1]);
                int i2 = j1, j2 = n - 1 - i1;
                swap(matrix[i][j], matrix[i2][j2]);
                int i3 = j2, j3 = n - 1 - i2;
                swap(matrix[i][j], matrix[i3][j3]);
                
            }
        }
        
    }
};