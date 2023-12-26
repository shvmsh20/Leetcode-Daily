int mod = 1e9+7;
    int solve(int dices, int faces, int target, vector<vector<long long>> &dp){
        
        if(dices==0 && target!=0){
            return 0;
        }
        if(target==0 && dices!=0){
            return 0;
        }
        if(target==0 && dices==0){
            return 1;
        }
        if(dp[dices][target]!=-1){
            return dp[dices][target];
        }
        long long ans = 0;
        for(int i=1; i<=faces; i++){
            if(i>target){
                break;
            }
            ans = ((ans%mod)+(solve(dices-1, faces, target-i, dp)%mod))%mod;
        }
        return dp[dices][target] = ans%mod;
    }
    int numRollsToTarget(int dices, int faces, int target) {
        vector<vector<long long>> dp(dices+1, vector<long long> (max(faces, target)+1));
        dp[0][0] = 1;
        for(int i=1; i<=dices; i++){
            for(int j=1; j<=target; j++){
                long long ans = 0;
                for(int k=1; k<=faces; k++){
                    if(k>j){
                        break;
                    }
                    ans = (ans%mod + dp[i-1][j-k]%mod)%mod;
                }
                dp[i][j] = ans;
            }
        }
        return dp[dices][target];
    }