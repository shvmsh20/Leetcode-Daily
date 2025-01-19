 struct cmp{
        bool operator()(vector<int> &a, vector<int> &b){
            return a[2]>b[2];
        }
    };
    int trapRainWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i=0; i<n; i++){
            pq.push({i, 0, grid[i][0]});
            pq.push({i, m-1, grid[i][m-1]});
            vis[i][0] = true;
            vis[i][m-1] = true;
        }
        for(int j=0; j<m; j++){
            pq.push({0, j, grid[0][j]});
            pq.push({n-1, j, grid[n-1][j]});
            vis[0][j] = true;
            vis[n-1][j] = true;
        }
        int res = 0;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};
        while(!pq.empty()){
            vector<int> t = pq.top();
            pq.pop();
            int x = t[0], y = t[1], h = t[2];
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==false){
                    if(grid[nx][ny]>=h){
                        pq.push({nx, ny, grid[nx][ny]});
                    }else{
                        res+= h-grid[nx][ny];
                        pq.push({nx, ny, h});
                    }
                    vis[nx][ny] = true;
                }
            }
        }
        return res;
        
    }