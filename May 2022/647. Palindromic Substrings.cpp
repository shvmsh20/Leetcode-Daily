nt countSubstrings(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; i++, j++){
                if(gap==0){
                    dp[i][j]=1;
                }else if(gap==1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=0;
                    }
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1]==1){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=0;
                    }
                }
            }
        }
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }