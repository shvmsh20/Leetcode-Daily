int dx[2] = {0, 1};
    int dy[2] = {1, 0};
    int dfs(int x, int y, int n, int m, vector<vector<int>>& grid, 
    vector<vector<bool>> &vis, int k, vector<vector<vector<int>>> &dp){
        k = k - (grid[x][y]==2?1:grid[x][y]);
        if(k<0){
            return -1;
        }
        if(dp[x][y][k]!=-2){
            return dp[x][y][k];
        }
        vis[x][y] = true;
        if(x==n-1 && y==m-1){
            vis[x][y] = false;
            return grid[x][y];
        }
        int res = -1;
        for(int i=0; i<2; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                res = max(res, dfs(nx, ny, n, m, grid, vis, k, dp));
            }
        }
        vis[x][y] = false;
        return dp[x][y][k] =( res!=-1?(res+grid[x][y]):-1);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -2)));
        int res = dfs(0, 0, n, m, grid, vis, k, dp);
        return res;
    }