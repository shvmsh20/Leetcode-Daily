int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                v[i][j] = grid[i][j]+(j-1>=0?v[i][j-1]:0)+
                (i-1>=0?v[i-1][j]:0)
                -((i-1>=0&&j-1>=0)?v[i-1][j-1]:0);
            }
        }
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]<=k){
                    res++;
                }
            }
        }
        return res;
    }