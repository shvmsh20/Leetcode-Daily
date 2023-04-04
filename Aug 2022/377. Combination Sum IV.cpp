int combinationSum4(vector<int>& nums, int target){
        vector<size_t> dp(target+1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; i++){
            int count=0;
            
            for(int j=0; j<nums.size(); j++){
                if(nums[j]<=i){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }