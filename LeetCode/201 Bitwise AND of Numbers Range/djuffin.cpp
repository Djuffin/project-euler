int rangeBitwiseAnd(int m, int n) {
        
        int x = m ^ n;
        int mask = 0;
        if (n == m) return n;
        
        while (x) {
            x >>= 1;
            mask = (mask << 1) | 1;
        };
        
        return n & (~mask);    
}