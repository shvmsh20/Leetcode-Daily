int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mn = INT_MAX;
        for(int k=i; k<=j; k++){
            int cost = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp);
            mn = min(mn, cost);
        }
        return dp[i][j] = mn;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int> (size, -1));
        return solve(1, size-2, cuts, dp);
    }