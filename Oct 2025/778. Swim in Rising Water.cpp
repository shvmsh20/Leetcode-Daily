int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int ans = INT_MAX;
    void dfs(int x, int y, int n, vector<vector<int>>& grid, vector<vector<bool>> &vis, int curr){
        vis[x][y] = true;
        curr = max(curr, grid[x][y]);
        if(x==n-1 && y==n-1){
            ans = min(ans, curr);
            vis[x][y] = false;
            return;
        }
        if(curr>ans){
            vis[x][y] = false;
            return;
        }
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n && vis[nx][ny]==false){
                dfs(nx, ny, n, grid, vis, curr);
            }
        }
        vis[x][y] = false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        dfs(0, 0, n, grid, vis, 0);
        return ans;
    }