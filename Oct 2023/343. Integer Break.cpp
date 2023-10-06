int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            int res=0;
            if(i!=n){
                res = i;
            }
            for(int j=1; j<i; j++){
                int val = dp[j]*dp[i-j];
                res = max(res, val);
            }
            dp[i] = res;
        }
        return dp[n];
    }