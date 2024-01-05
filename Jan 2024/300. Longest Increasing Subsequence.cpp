int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            int res = 1;
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    res = max(res, 1+dp[j]);
                }
            }
            dp[i] = res;
        }
        int res = 1;
        for(int i=0; i<n; i++){
            res = max(res, dp[i]);
        }
        return res;
    }