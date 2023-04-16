int solve(vector<int> &coins, int index, int amount, vector<vector<int>> &dp){
        if(amount==0){
            return 0;
        }
        if(index==-1){
            return INT_MAX-1;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int res;
        if(coins[index]<=amount){
            res = min(1+solve(coins, index, amount-coins[index], dp), solve(coins, index-1, amount, dp));
        }else{
            res = solve(coins, index-1, amount, dp);
        }
        return dp[index][amount] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int res = solve(coins, n-1, amount, dp);
        return res==(INT_MAX-1)?-1:res;
    }