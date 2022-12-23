 int solve(int index, int prevBuy, vector<int> &prices, vector<vector<int>> &dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][prevBuy+1]!=-1){
            return dp[index][prevBuy+1];
        }
        if(prevBuy==-1){
            return dp[index][prevBuy+1] = max(solve(index+1, index, prices, dp), solve(index+1, prevBuy, prices, dp));
        }else if(prices[prevBuy]<prices[index]){
            return dp[index][prevBuy+1] = max(solve(index+1, prevBuy, prices, dp), prices[index]-prices[prevBuy]+solve(index+2, -1, prices, dp));
        }else{
            return dp[index][prevBuy+1] = solve(index+1, prevBuy, prices, dp);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, prices, dp);
    }