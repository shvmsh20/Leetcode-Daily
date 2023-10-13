nt solve(int index, int n, vector<int> &cost, vector<int> &dp){
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        return dp[index] = cost[index]+min(solve(index+1, n, cost, dp), solve(index+2, n, cost, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(solve(0, n, cost, dp), solve(1, n, cost, dp));
    }