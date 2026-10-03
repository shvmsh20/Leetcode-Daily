int longestValidParentheses(string s) {
        int n = s.size();
        int mx = 0;
        vector<int> dp(n+1, 0);
        for(int i=1; i<n; i++){
            int j = i-dp[i]-1;
            if(j>=0 && s[i]==')' && s[j]=='('){
                dp[i+1] = dp[i]+dp[j]+2;
            }
            mx = max(mx, dp[i+1]);
        }
        return mx;
    }