bool solve(int i, int j, int k, int n1, int n2, int n3, string &s1, string &s2, string &s3, 
              unordered_map<string, bool> &dp){
        if(i==n1 && j==n2 && k==n3){
            return true;
        }
        string chck = to_string(i)+'#'+to_string(j);
        if(dp.find(chck)!=dp.end()){
            return dp[chck];
        }
        if(i<n1 && j<n2){
            if(s1[i]==s3[k] && s2[j]==s3[k]){
                return dp[chck] = solve(i+1, j, k+1, n1, n2, n3, s1, s2, s3, dp) || 
                    solve(i, j+1, k+1, n1, n2, n3, s1, s2, s3, dp);
            }
            if(s1[i]==s3[k]){
                return dp[chck] = solve(i+1, j, k+1, n1, n2, n3, s1, s2, s3, dp);
            }
            if(s2[j]==s3[k]){
                return dp[chck] = solve(i, j+1, k+1, n1, n2, n3, s1, s2, s3, dp);
            }
            return dp[chck] = false;
        }else if(i<n1){
            if(s1[i]==s3[k]){
                return dp[chck] = solve(i+1, j, k+1, n1, n2, n3, s1, s2, s3, dp);
            }else{
                return dp[chck] = false;
            }
        }else{
            if(s2[j]==s3[k]){
                return dp[chck] = solve(i, j+1, k+1, n1, n2, n3, s1, s2, s3, dp);
            }else{
                return dp[chck]= false;
            }
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        int i=0, j=0, k=0;
        unordered_map<string, bool> dp;
        if(n1+n2!=n3){
            return false;
        }
        return solve(i, j, k, n1, n2, n3, s1, s2, s3, dp);
    }