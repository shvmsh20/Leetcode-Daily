void dfs(int x, int y, int n, int m, int prevVal, vector<vector<int>> &heights, set<vector<int>> &vis){
        if(x<0 || x==n || y<0 || y==m || vis.find({x, y})!=vis.end() || heights[x][y]<prevVal){
            return;
        }
        vis.insert({x, y});
        dfs(x+1, y, n, m, heights[x][y], heights, vis);
        dfs(x-1, y, n, m, heights[x][y], heights, vis);
        dfs(x, y+1, n, m, heights[x][y], heights, vis);
        dfs(x, y-1, n, m, heights[x][y], heights, vis);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int n = heights.size();
        int m = heights[0].size();
        set<vector<int>> pac;
        set<vector<int>> atl;
        for(int i=0; i<n; i++){
            dfs(i, 0, n, m, heights[i][0], heights, pac);
            dfs(i, m-1, n, m, heights[i][m-1], heights, atl);
        }
        for(int j=0; j<m; j++){
            dfs(0, j, n, m, heights[0][j], heights, pac);
            dfs(n-1, j, n, m, heights[n-1][j], heights, atl);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pac.find({i, j})!=pac.end() && atl.find({i, j})!=atl.end()){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }