int helper(int n){
        return log2(n)+1;
    }
    int concatenatedBinary(int n) {
        long long res = 1;
        int mod = 1e9+7;
        for(int i=2; i<=n; i++){
            int m = helper(i);
            //.cout << i << " " << m << endl;
            res = (res << m)%mod;
            res = (res + i)%mod;
        }
        return res;
    }