int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1){
            return -1;
        }
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        queue<vector<int>> q;
        
        q.push({0, 0, 1});
        int dir[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto p = q.front();
                q.pop();
                int x = p[0];
                int y = p[1];
                if(x==n-1 && y==n-1){
                    return p[2];
                }
                int nx, ny;
                for(int i=0; i<8; i++){
                    nx = x+dir[i][0];
                    ny = y+dir[i][1];
                
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                    grid[nx][ny] = 1;
                    q.push({nx, ny, 1+p[2]});
                }
                }
            }
        }
        return -1;
    }