string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++){
            dp[i][0] = 0;
        }
        for(int i=0; i<=n; i++){
            dp[0][i] = 0;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string ans="";
        int i=m, j=n;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(str1[i-1]);
                    i--;
                }else{
                    ans.push_back(str2[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(str2[j-1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }