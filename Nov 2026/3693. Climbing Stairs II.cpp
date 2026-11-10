int solve(int currStair, int n, vector<int> &cost, vector<int> &dp){
        if(currStair==n){
            return 0;
        }
        if(dp[currStair]!=-1){
            return dp[currStair];
        }
        // 1 step
        long res = cost[currStair]+1+ solve(currStair+1, n, cost, dp);
        //  2 step
        if(currStair+2<=n){
            long tmp = cost[currStair+1]+4+ solve(currStair+2, n, cost, dp);
            res = min(tmp, res);
        }
        if(currStair+3<=n){
          
            long tmp = cost[currStair+2]+9+ solve(currStair+3, n, cost, dp);
            res = min(res, tmp);
        }
        return dp[currStair] = res;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
       return solve(0, n, costs, dp); 
    }