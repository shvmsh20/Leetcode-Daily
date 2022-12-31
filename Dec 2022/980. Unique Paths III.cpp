int res = 0, posW = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    void dfs(int sx, int sy, int ex, int ey, int n, int m, vector<vector<int>>& grid, vector<vector<bool>> &vis, int currW){
        currW++;
        if(sx==ex && sy==ey){
            if(currW==posW){
                res++;
            }
            return;
        }
        vis[sx][sy] = true;
        for(int i=0; i<4; i++){
            int x = sx+dx[i];
            int y = sy+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]!=-1 && vis[x][y]==false){
                dfs(x, y, ex, ey, n, m, grid, vis, currW);
            }
        }
        vis[sx][sy]=false;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int sx, ex, sy, ey, currW=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=-1){
                    posW++;
                }
                if(grid[i][j]==1){
                    sx = i;
                    sy = j;
                }
                if(grid[i][j]==2){
                    ex = i;
                    ey = j;
                }
                
            }
        }
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        dfs(sx, sy, ex, ey, n, m, grid, vis, currW);
        return res;
    }