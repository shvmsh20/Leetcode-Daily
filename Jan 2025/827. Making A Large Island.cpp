int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int solve(int x, int y, int n, vector<vector<int>>& grid, int key){
        int res = 1;
        grid[x][y] = key;
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==1){
                res+= solve(nx, ny, n, grid, key);
            }
        }
        return res;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> mp;
        int key = 2;
        int mx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int ans = solve(i, j, n, grid, key);
                    mx = max(mx, ans);
                    mp[key] = ans;
                    key++;
                }
            }
        }
        if(mx==n*n){
            return n*n;
        }
        if(mx==0){
            return 1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    int res = 1;
                    unordered_set<int> s;
                    for(int k=0; k<4; k++){
                        int ni = i+dx[k];
                        int nj = j+dy[k];
                        string temp = to_string(ni)+'#'+to_string(nj);
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]!=0){
                           int key = grid[ni][nj];
                           if(s.find(key)==s.end()){
                                res+= mp[key];
                                s.insert(key); 
                           }
                           
                        }
                    }
                    mx = max(mx, res);
                }
            }
        }
        return mx;
    }