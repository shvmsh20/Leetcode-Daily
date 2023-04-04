int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid){
        grid[x][y] = '0';
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='1'){
                dfs(nx, ny, n, m, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        return count;
    }