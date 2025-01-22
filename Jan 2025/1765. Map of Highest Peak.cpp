vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> q;
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]){
                    isWater[i][j] = 0;
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int curr = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for(int j=0; j<4; j++){
                    int nx = x+dx[j], ny = y+dy[j];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && visited[nx][ny]==0){
                        visited[nx][ny] = 1;
                        // cout << nx << " " << ny << endl;
                        q.push({nx, ny});
                        isWater[nx][ny] = curr+1;
                    }
                }
            }
            curr++;
        }
        return isWater;
    }