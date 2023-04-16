int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& dist, 
             int n, int m, int x, int y){
        int mx=1;
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && matrix[nx][ny]>matrix[x][y]){
                if(dist[nx][ny]==-1){
                    dfs(matrix, dist, n, m, nx, ny);
                }
                mx = max(mx, 1+dist[nx][ny]);
            }
        }
        dist[x][y]=mx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dist(n, vector<int> (m, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dist[i][j]==-1){
                    dfs(matrix, dist, n, m, i, j);
                }
            }
        }
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mx = max(mx, dist[i][j]);
            }
        }
        return mx;
    }