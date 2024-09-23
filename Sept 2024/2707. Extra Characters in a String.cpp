int solve(int index, int n, string &s, unordered_set<string> &dic, vector<int> &dp){
        if(index==n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int size = 0, res = 50;
        string x;
        for(int i=index; i<n; i++){
            size++;
            x+=s[i];
            int t = solve(i+1, n, s, dic, dp);
            if(dic.find(x)!=dic.end()){
                res = min(res, t);
            }else{
                res = min(res, size+t);
            }
        }
        return dp[index] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dic;
        for(string x: dictionary){
            dic.insert(x);
        }
        vector<int> dp(n, -1);
        return solve(0, n, s, dic, dp);
    }