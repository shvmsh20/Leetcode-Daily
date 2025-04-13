int mod = 1e9+7;
    int solve(int x, long long y){
        if(y==0){
            return 1;
        }
        if(y==1){
            return x;
        }
        long long t = solve(x, y/2);
        if(y&1){
            return (x*(t*t)%mod)%mod;
        }
        return (t*t)%mod;
    }
    int countGoodNumbers(long long n) {
       return (((long long)solve(4, n/2)%mod) * ((long long)solve(5, n-n/2))%mod)%mod;
    }