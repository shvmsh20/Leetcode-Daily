double champagneTower(int poured, int query_row, int query_glass) {
        int n = 101;
        vector<vector<double>> dp(n, vector<double>(n));
        dp[0][0] = poured;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<=i; j++){
                if(dp[i][j]>1){
                    dp[i+1][j] += (dp[i][j]-1.00)/2.00;
                    dp[i+1][j+1] += (dp[i][j]-1.00)/2.00;
                    dp[i][j] = 1;
                }
            }
        }
        return dp[query_row][query_glass];
    }