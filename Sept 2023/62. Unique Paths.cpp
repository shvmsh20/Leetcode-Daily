int solve(int x, int y, int m, int n, vector<vector<int>> &dp){
        if(x==m || y==n){
            return 0;
        }
        if(x==m-1 && y==n-1){
            return 1;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int res = 0;
        res+= solve(x+1, y, m, n, dp);
        res+= solve(x, y+1, m, n, dp);
        return dp[x][y] = res;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }