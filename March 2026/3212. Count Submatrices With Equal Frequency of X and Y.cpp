int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>(m));
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int xCnt = 0, yCnt = 0;
                if(grid[i][j]=='X'){
                    xCnt++;
                }else if(grid[i][j]=='Y'){
                    yCnt++;
                }
                if(i-1>=0){
                    xCnt+= v[i-1][j].first;
                    yCnt+= v[i-1][j].second;
                }
                if(j-1>=0){
                    xCnt+= v[i][j-1].first;
                    yCnt+= v[i][j-1].second;
                }
                if(i-1>=0 && j-1>=0){
                    xCnt-= v[i-1][j-1].first;
                    yCnt-= v[i-1][j-1].second;
                }
                if(xCnt && xCnt==yCnt){
                    res++;
                }
                v[i][j] = {xCnt, yCnt};
            }
        }
        return res;
    }