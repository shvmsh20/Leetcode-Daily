int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size();
        int m = t2.size();
        vector<int> prev(m+1);
        vector<int>curr(m+1);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(t1[i-1]==t2[j-1]){
                    curr[j] = 1+prev[j-1];
                }else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
        
    }
    