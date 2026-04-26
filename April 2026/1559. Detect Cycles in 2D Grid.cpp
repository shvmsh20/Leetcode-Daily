int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool dfs(int x, int y, int n, int m, vector<vector<char>> &grid, int px, int py, vector<vector<bool>> &vis){
        vis[x][y] = true;
        for(int i=0; i<4; i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==grid[x][y] && !(nx==px && ny==py)){
                if(vis[nx][ny]){
                    return true;
                }
                if(dfs(nx, ny, n, m, grid, x, y, vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==false && dfs(i, j, n, m, grid, -1, -1, vis)){
                    return true;
                }
            }
        }
        return false;
    }