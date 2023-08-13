bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i=n-1; i>=0; i--){
            if(i+1<n && nums[i]==nums[i+1]){
                dp[i] = max(dp[i], dp[i+2]);
            }
            if(i+2<n && ((nums[i]==nums[i+1] && nums[i+1]==nums[i+2]) || (nums[i]+1==nums[i+1] && nums[i]+2==nums[i+2]))){
                dp[i] = max(dp[i], dp[i+3]);
            }
        }
        return dp[0];
    }