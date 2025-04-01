long long solve(int index, int n, vector<vector<int>> &q,  vector<long long> &dp){
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        
        long long res = solve(index+1, n, q, dp);
        res = max(res, q[index][0]+solve(index+q[index][1]+1, n, q, dp));
        
        return dp[index] = res;
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n+1, -1);
        return solve(0, n, q, dp);
    }