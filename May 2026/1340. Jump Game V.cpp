int solve(int index, vector<int> &arr, int d, vector<int> &dp, int n){
        if(dp[index]!=-1){
            return dp[index];
        }
        int res = 0;
        for(int i=index-1; i>=0 && i>=index-d; i--){
            if(arr[index]<=arr[i]){
                break;
            }
            res = max(res, solve(i, arr, d, dp, n));
        }
        for(int i=index+1; i<n && i<=index+d; i++){
            if(arr[index]<=arr[i]){
                break;
            }
            res = max(res, solve(i, arr, d, dp, n));
        }
        dp[index] = res+1;
        return res+1;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int res = 0;
        vector<int> dp(n, -1);
        for(int i=0; i<n; i++){
            res = max(res, solve(i, arr, d, dp, n));
        }
        return res;
    }