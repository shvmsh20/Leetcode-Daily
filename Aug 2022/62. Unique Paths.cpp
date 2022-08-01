int nCr(int n, int r){
        long long res = 1;
        for(int i=0; i<r; i++){
            res*= (n-i);
            res/= (i+1);
        }
        return (int)res;
    }
    int uniquePaths(int m, int n) {
         int N = m+n-2;
         int R = min(m-1, n-1);
         return nCr(N, R);
    }