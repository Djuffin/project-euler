class Solution {
    static const int n = 9;
    int rows[n] = {};
    int columns[n] = {};
    int squares[n] = {};
    
    bool is_set(int array, int i) {
        return (array & (1 << i)) != 0;
    }
    
    void set(int &array, int i, bool value) {
        if (value) {
            array |= 1 << i;
        } else {
            array &= ~(1 << i);
        }
    }
    
    int get_sq(int row, int column) {
        return (row / 3) * 3 + (column / 3);
    }
    
    void mark(int row, int column, int digit, bool value) {
        set(rows[row], digit, value);
        set(columns[column], digit, value);
        set(squares[get_sq(row, column)], digit, value);
    }
    
    bool is_marked(int row, int column, int digit) {
        return  is_set(rows[row], digit) ||
                is_set(columns[column], digit) ||
                is_set(squares[get_sq(row, column)], digit);
    }
    
    bool search(vector<vector<char>>& board, int i) {
        if (i == n * n) return true;
        int row = i / n;
        int column = i % n;
        if (board[row][column] != '.') {
            return search(board, i + 1);
        }
        for (int digit = 0; digit < 9; digit++) {
            if(!is_marked(row, column, digit)) {
                mark(row, column, digit, true);
                
                if (search(board, i + 1)) {
                    board[row][column] = '1' + digit;
                    return true;
                }
                
                mark(row, column, digit, false);
                
            }
        }
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        //populate known
        for (int row = 0; row < n; row++) {
            for (int column = 0; column < n; column++) {
                if (board[row][column] != '.') {
                    mark(row, column, board[row][column] - '1', true);
                }
            }
        }
        
        //solve
        bool result = search(board, 0);
        assert(result);
    }
};