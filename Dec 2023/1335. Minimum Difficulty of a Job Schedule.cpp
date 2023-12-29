int solve(int index, int n, vector<int> &jd, int d, vector<vector<int>> &dp){
        if(d==0 && index==n){
            return 0;
        }
        if(d==0){
            return INT_MAX;
        }
        if(dp[index][d]!=-1){
            return dp[index][d];
        }
        long long ans = LLONG_MAX;
        long long curr = 0;
        int mx = INT_MIN;
        for(int i=index; i<n-(d-1); i++){
            mx = max(mx, jd[i]);
            curr = (long long)mx+solve(i+1, n, jd, d-1, dp);
            ans = min(ans, curr);
            
        }
        //cout << ans << " ";
        return dp[index][d] = ans;
    }
    int minDifficulty(vector<int>& jd, int D) {
        int n = jd.size();
        if(n<D){
            return -1;
        }
        vector<vector<int>> dp(n+1, vector<int> (D+1));
        dp[n][0] = 0;
        for(int i=0; i<n; i++){
            dp[i][0] = INT_MAX;
        } 
        for(int index = n-1; index>=0; index--){
            for(int d = 1; d<=D; d++){
                long long ans = LLONG_MAX;
                long long curr = 0;
                int mx = INT_MIN;
                for(int i=index; i<n-(d-1); i++){
                    mx = max(mx, jd[i]);
                    curr = (long long)mx+dp[i+1][d-1];
                    ans = min(ans, curr);

                }
                dp[index][d] = ans;
            }
        }
        return dp[0][D];
    }