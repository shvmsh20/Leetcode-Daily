int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int dfs(int x, int y, int n, int m, vector<vector<int>> &grid){
        int res = grid[x][y];
        grid[x][y] = -1;
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]>0){
                res+= dfs(nx, ny, n, m, grid);
            }
        }
        return res;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]>0){
                    res = max(res, dfs(i, j, n, m, grid));
                }
            }
        }
        return res;
    }