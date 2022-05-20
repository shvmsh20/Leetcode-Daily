int util(vector<vector<int>>& obstacleGrid, int x, int y, int n, int m, 
            vector<vector<int>> &dp){
        if(x==n-1 && y==m-1 && obstacleGrid[x][y]==0){
            return 1;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int right = 0;
        int  down = 0;
        if(x+1<n && obstacleGrid[x+1][y]==0){
            if(dp[x+1][y]!=-1){
                right = dp[x+1][y];
            }else{
                right = util(obstacleGrid, x+1, y, n, m, dp);
                dp[x+1][y] = right;
            }
        }
        if(y+1<m && obstacleGrid[x][y+1]==0){
            if(dp[x][y+1]!=-1){
                down = dp[x][y+1];
            }else{
                down = util(obstacleGrid, x, y+1, n, m, dp);
                dp[x][y+1] = down;
            }
        }
        
        return dp[x][y] = right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return util(obstacleGrid, 0, 0, n, m, dp);
    }