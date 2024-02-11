int dx[3] = {1, 1, 1};
    
int dy[3] = {-1, 0, 1};

int solve(int x1, int y1, int x2, int y2, int n, int m, vector<vector<int>> &grid, unordered_map<string, int> &dp) {
    if (x1 >= n || y1 < 0 || y1 >= m || x2 >= n || y2 < 0 || y2 >= m) {
        return 0;
    }
    string key = to_string(x1)+'#'+to_string(y1)+'#'+to_string(x2)+'#'+to_string(y2);
    if(dp.find(key)!=dp.end()){
        return dp[key];
    }
    int currCellVal = 0;
    if (x1 == x2 && y1 == y2) {
        currCellVal = grid[x1][y1];
    } else {
        currCellVal = grid[x1][y1] + grid[x2][y2];
    }
    int res = INT_MIN;
    for (int i = 0; i < 3; i++) {
        int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
        int mx1 = INT_MIN;
        for (int j = 0; j < 3; j++) {
            int nx2 = x2 + dx[j], ny2 = y2 + dy[j];
            mx1 = max(mx1, currCellVal + solve(nx1, ny1, nx2, ny2, n, m, grid, dp));
        }
        res = max(res, mx1);
    }
    return dp[key] = res;
}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    unordered_map<string, int> dp;
    return solve(0, 0, 0, m - 1, n, m, grid, dp);
}