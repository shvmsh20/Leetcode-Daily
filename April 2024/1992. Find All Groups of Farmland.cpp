int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    vector<int> dfs(int x, int y, int n, int m, vector<vector<int>> &land){
        vector<int> res = {x, y};
        land[x][y] = 0;
        for(int i=0; i<4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && land[nx][ny]==1){
                vector<int> v = dfs(nx, ny, n, m, land);
                res[0] = max(res[0], v[0]);
                res[1] = max(res[1], v[1]);
            }
        }
        return res;
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int n = land.size(), m = land[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j]==1){
                    vector<int> br = dfs(i, j, n, m, land);
                    res.push_back({i, j, br[0], br[1]});
                }
            }
        }
        return res;
    }