class Solution {
    bool mark(int used[9], char c) {
        if (c == '.') return true;
        return (++used[c - '1']) < 2;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;
        
        //validate rows
        for (auto &v: board) {
            int used[n] = {};
            for (char c:v) {
                if (!mark(used, c))
                    return false;
            }
        }
        
        //validate columns
        for (int i = 0; i < n; i++) {
            int used[n] = {};
            for (int j = 0; j < n; j++) {
                if (!mark(used, board[j][i]))
                    return false;
            }
        }
        
        //validate squares
        for (int sq = 0; sq < n; sq++) {
            int used[n] = {};
            for (int i = 0; i < n; i++) {
                int column = (sq % 3) * 3 + i % 3;
                int row = (sq / 3) * 3 + i / 3;
                if (!mark(used, board[row][column]))
                    return false;
            }
        }
        
        return true;
        
    }
};