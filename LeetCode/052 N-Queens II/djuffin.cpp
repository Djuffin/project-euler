    struct Queen {
        int file, rank;
        
        int diag1(int n) {
            return file + rank;    
        }
        
        int diag2(int n) {
            return rank + (n - 1 - file);
        }
        
        Queen() : file(0), rank(0)
        {}
        
        
        Queen(int f, int r) : file(f), rank(r)
        {}
    };

class Solution {
    vector<bool> rank, file, diag1, diag2;
    int n;
    int result;
    

    
    bool try_put(Queen p) {
        return (!rank[p.rank]) &&
               (!file[p.file]) &&
               (!diag1[p.diag1(n)]) &&
               (!diag2[p.diag2(n)]);
               
    }
    
    void put(Queen p, bool v) {
        rank[p.rank] = file[p.file] = diag1[p.diag1(n)] = diag2[p.diag2(n)] = v;
               
    }
    
    void next_rank(int rank) {
        
        for (int file = 0; file < n; file++) {
            Queen p(file, rank);
            if (try_put(p)) {
                put(p, true);
               
            
            
                if (rank == n - 1) {
                    result++;
                } else {
                    next_rank(rank + 1);
                }
              
                put(p, false);
            }
        }
    }
 

public:
    int totalNQueens(int n) {
        rank.resize(n);
        file.resize(n);
        diag1.resize(n * 2);
        diag2.resize(n * 2);
        this->n = n;
        
        next_rank(0);
        return result;        
    }
};