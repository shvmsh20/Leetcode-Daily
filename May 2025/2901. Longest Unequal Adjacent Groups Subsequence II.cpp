int hammingDist(string &s1, string &s2){
        int cnt = 0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                cnt++;
            }
            if(cnt>1){
                return cnt;
            }
        }
        return 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& w, vector<int>& gp) {
        int n = w.size();
        vector<vector<int>> dp(n);
        for(int i=0; i<n; i++){
            dp[i] = {i};
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(gp[i]!=gp[j] && w[i].size()==w[j].size() &&  hammingDist(w[i], w[j])==1){
                    if(dp[i].size()<1+dp[j].size()){
                        dp[i] = dp[j];
                        dp[i].push_back(i);
                    }
                }
            }
        }
        int cnt = 0, index = 0;
        for(int i=0; i<n; i++){
            if(cnt<dp[i].size()){
                index = i;
                cnt = dp[i].size();
            }
        }
        sort(dp[index].begin(), dp[index].end());
        vector<string> res;
        for(int i=0; i<dp[index].size(); i++){
            res.push_back(w[dp[index][i]]);
        }
        return res;
    }