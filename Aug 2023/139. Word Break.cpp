bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> mp;
        for(string x: wordDict){
            mp.insert(x);
        }
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; i++, j++){
                if(gap==0){
                    if(mp.find(s.substr(i, j-i+1))!=mp.end()){
                        dp[i][j] = true;
                    }
                }else{
                   if(mp.find(s.substr(i, j-i+1))!=mp.end()){
                        dp[i][j] = true;
                    }else{
                       for(int k=i; k<j; k++){
                           if(dp[i][k] && dp[k+1][j]){
                               dp[i][j] = true;
                               break;
                           }
                       }
                   }
                }
            }
        }
        return dp[0][n-1];
    }