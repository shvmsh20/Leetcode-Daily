int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz+1, vector<vector<int>> (m+1, vector<int> (n+1)));
        
        for(int i=1; i<=sz; i++){
            int zeros = count(strs[i-1].begin(), strs[i-1].end(), '0');
            int ones = strs[i-1].length()-zeros;
            for(int j=0; j<=m; j++){
                for(int k=0; k<=n; k++){
                    if(j>=zeros && k>=ones){
                        dp[i][j][k] = max(1+dp[i-1][j-zeros][k-ones], dp[i-1][j][k]);
                    }else{
                        dp[i][j][k] = dp[i-1][j][k];
                    }
                }
            } 
        }
        return dp[sz][m][n];
    }