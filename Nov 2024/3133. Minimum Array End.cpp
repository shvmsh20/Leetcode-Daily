long long minEnd(int n, int x) {
        long long res = x;
        for(int i=1; i<=n-1; i++){
            res = (res+1) | x;
        }
        return res;
    }