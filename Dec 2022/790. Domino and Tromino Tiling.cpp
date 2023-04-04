int numTilings(int n) {
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }else if(n==2){
            return 2;
        }else if(n==3){
            return 5;
        }
        int mod = 1e9+7;
        vector<int> res(n+1);
        res[1] = 1;
        res[2] = 2;
        res[3] = 5;
        for(int i=4; i<=n; i++){
            res[i] = ((2*res[i-1])%mod + res[i-3]%mod)%mod;
        }
        return res[n];
    }