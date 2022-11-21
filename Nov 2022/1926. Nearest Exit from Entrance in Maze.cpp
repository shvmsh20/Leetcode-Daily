int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> q;
        int row = maze.size(), col = maze[0].size();
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                vector<int> v = q.front();
                q.pop();
                int x = v[0], y = v[1], dist = v[2];
                if(!(x==entrance[0] && y==entrance[1]) && (x==0 || x==(row-1) || y==0 || y==(col-1))){
                    return dist;
                }
                //cout << x << " " << y << endl;
                for(int i=0; i<4; i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx>=0 && nx<row && ny>=0 && ny<col && maze[nx][ny]=='.'){
                        q.push({nx, ny, dist+1});
                        maze[nx][ny] = '+';
                    }
                }
            }
            
        }
        return -1;
    }