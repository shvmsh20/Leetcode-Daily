int solve(int index, int n, string &s, vector<int> &dp){
        if(index==n){
            return 1;
        }
        if(s[index]=='0'){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int res = 0;
        res+= solve(index+1, n, s, dp);
        if((index+1)<n){
            string temp = s.substr(index, 2);
            int num = stoi(temp);
            if(num<=26){
                res+= solve(index+2, n, s, dp);
            }
        }
        return dp[index] = res;
    }
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, n, s, dp);
    }