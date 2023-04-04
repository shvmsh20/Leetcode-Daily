int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>> &vis){
        int count=0;
        vis[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()){
            int sz = q.size();
            count+= sz;
            while(sz--){
                pair p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for(int i=0; i<4; i++){
                    int nx = x+dx[i], ny = y+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==false && grid[nx][ny]==1){
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> vis(r, vector<bool> (c, false));
        int ans = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1 && vis[i][j]==false){
                    int t = solve(i, j, r, c, grid, vis);
                    ans = max(ans, t);
                }
            }
        }
        return ans;
    }