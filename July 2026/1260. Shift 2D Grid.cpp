 vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> v(n, vector<int> (m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int index = ((i*m +j)+k)% (n*m);

                int r = index/m;
                int c = index%m;
                v[r][c] = grid[i][j];
                
            }
            
            
        }
        return v;
    }