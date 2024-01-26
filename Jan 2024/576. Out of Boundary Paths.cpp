int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int mod = 1e9+7;
    int solve(int x, int y, int m, int n, int maxMove, vector<vector<vector<int>>> &dp){
        if(x<0 || x==m || y<0 || y==n){
            return 1;
        }
        if(maxMove==0){
            return 0;
        }
        if(dp[x][y][maxMove]!=-1){
            return dp[x][y][maxMove];
        }
        int res = 0;
        for(int i=0; i<4; i++){
            res = (res + (solve(x+dx[i], y+dy[i], m, n, maxMove-1, dp)%mod))%mod;
        }
        return dp[x][y][maxMove] = res;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(51, vector<vector<int>> (51, vector<int>(51, -1)));
        return solve(startRow, startColumn, m, n, maxMove, dp);
        
    }