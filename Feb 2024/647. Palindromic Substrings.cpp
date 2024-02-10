int countSubstrings(string s) {
        int n = s.length(), count=0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(i==j){
                    dp[i][j] = 1;
                    count++;
                }else if(i+1==j && s[i]==s[j]){
                    dp[i][j] = 1;
                    count++;
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        count++;
                        dp[i][j] = 1;
                    }
                }
            }
        }
        return count;
    }