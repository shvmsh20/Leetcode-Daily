int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mod = 1e9+7;
        vector<vector<pair<long, long>>> v(n, vector<pair<long, long>>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0){
                    v[i][j] = {grid[i][j], grid[i][j]};
                    continue;
                }
                long mn = INT_MAX, mx = INT_MIN;
                if(i-1>=0){
                    pair<long, long> p = v[i-1][j];
                    mn = min(1L*grid[i][j]*p.first, 1L*grid[i][j]*p.second);
                    mx = max(1L*grid[i][j]*p.first, 1L*grid[i][j]*p.second);
                }
                if(j-1>=0){
                    pair<long, long> p = v[i][j-1];
                    mn = min(mn, min(1L*grid[i][j]*p.first, 1L*grid[i][j]*p.second));
                    mx = max(mx, max(1L*grid[i][j]*p.first, 1L*grid[i][j]*p.second));
                }
                v[i][j] = {mn, mx};
            }
        }
        int res = v[n-1][m-1].second%mod;
        return res<0?-1:res;
    }