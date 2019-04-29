class Solution {
    
    void mark(vector<vector<char>>& grid, vector<vector<bool>> &marked, int irow, int icolumn) {
        queue<pair<int, int>> q;
        q.push({irow, icolumn});
        
        while (!q.empty()) {
            auto pos = q.front(); 
            q.pop();
            int row = pos.first;
            int column = pos.second;
            if (row >= 0 && row < grid.size() && column >= 0 && column < grid[0].size()
                && !marked[row][column] && grid[row][column] == '1') {
            
                marked[row][column] = true;
                q.push({row - 1, column});
                q.push({row + 1, column});
                q.push({row, column - 1});
                q.push({row, column + 1});
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int islandCount = 0;
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<bool>> marked(rows, vector<bool>(columns));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == '1' && !marked[i][j]) {
                    islandCount++;
                    mark(grid, marked, i, j);
                }
            }
        }
        
        return islandCount;
        
    }
};