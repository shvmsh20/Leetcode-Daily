int solve(int aliceTurn, int i, int n, vector<int> &piles, int M,  vector<vector<vector<int>>> &dp){
        if(i>=n) return 0;
        if(dp[aliceTurn][i][M]!=-1){
            return dp[aliceTurn][i][M];
        }
        int res = aliceTurn?-1:INT_MAX, stones = 0;
        for(int x=1; x<=min(n-i, 2*M); x++){
            stones+= piles[i+x-1];
            if(aliceTurn){
                res = max(res, stones+solve(0, i+x, n, piles, max(x, M), dp));
            }else{
                res = min(res, solve(1, i+x, n, piles, max(x, M), dp));
            }
        }
        return dp[aliceTurn][i][M] = res;;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n+1, -1)));
        return solve(1, 0, n, piles, 1, dp);
    }