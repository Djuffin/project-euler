
struct Box {
    int w, h;
    
    public:
    Box() {
        w = h = 0;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<Box>> d;
        d.resize(matrix.size());
        int result = 0;
        
        for (int i = 0, size = matrix.size(); i < size; i++) {
            d[i].resize(matrix[i].size());
        }    
        
        for (int i = 0, size = matrix.size(); i < size; i++) {
            for (int j = 0, line_size = matrix[i].size(); j< line_size; j++) {
                
                if (matrix[i][j] == '1') {
                    Box up, left, diag;
                    if (i != 0) {
                        up = d[i - 1][j];
                    }
                    if (j != 0) {
                        left = d[i][j - 1];
                    }
                    if (i != 0 && j != 0) {
                        diag = d[i - 1][j - 1];
                    }
                    
                    Box r;
                    r.h = min(diag.h, up.h) + 1;
                    r.w = min(diag.w, left.w) + 1;
                    d[i][j] = r;
                    if (r.h == r.w) {
                        result = max(result, r.h * r.w);
                    }
                }
            }
            
        }
        
        return result;
    }
};