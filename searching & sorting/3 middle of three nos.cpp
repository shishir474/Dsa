 int middle(int A, int B, int C){
        int mx=max({A,B,C});
        int mn=min({A,B,C});
        
        return mx^mn^A^B^C;
        // or
        return A+B+C - (mx+mn);
    }