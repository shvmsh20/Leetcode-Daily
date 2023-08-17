vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};
        int level = 1;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j=0; j<4; j++){
                    int nx = x+dx[j];
                    int ny = y+dy[j];
                    
                    if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1 && vis[nx][ny]==false){
                        q.push({nx, ny});
                        mat[nx][ny] = level;
                        vis[nx][ny] = true;
                    }
                }
            }
            level++;
        }
        return mat;
    }