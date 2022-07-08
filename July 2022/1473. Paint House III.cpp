int dp[101][21][101];
    int solve(int currHouse, int prevColor, int t, vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        if(t>target) return INT_MAX/2;
        if(dp[currHouse][prevColor][t]!=-1) return dp[currHouse][prevColor][t];
        if(currHouse==m){
            return t==target?0:INT_MAX/2;
        }
        int ans = INT_MAX/2;
        if(houses[currHouse]==0){
            for(int i=0; i<n; i++){
                ans = min(ans, cost[currHouse][i]+solve(currHouse+1, i+1, i+1==prevColor?t:t+1, houses, cost, m, n, target));
            }
        }else{
            ans = min(ans, solve(currHouse+1, houses[currHouse], prevColor==houses[currHouse]?t:t+1, houses, cost, m, n, target));
        }
        return dp[currHouse][prevColor][t] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, 0, houses, cost, m, n, target);
        return ans==INT_MAX/2?-1:ans;
    }