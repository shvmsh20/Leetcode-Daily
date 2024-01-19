int solve(int x, int y, int n, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        int res = INT_MAX;
        if(dp[x][y]!=INT_MIN){
            return dp[x][y];
        }
        if((x+1)<n && (y-1)>=0){
            res = min(res, solve(x+1, y-1, n, matrix, dp));
        }
        if((x+1)<n){
            res = min(res, solve(x+1, y, n, matrix, dp));
        }
        if((x+1)<n && (y+1)<n){
            res = min(res, solve(x+1, y+1, n, matrix, dp));
        }
        return dp[x][y] = (res==INT_MAX?0:res)+matrix[x][y];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = INT_MAX;
        vector<vector<int>> dp(n, vector<int> (n, INT_MIN));
        for(int i=0; i<n; i++){
            res = min(res, solve(0, i, n, matrix, dp));
        }
        return res;
    }