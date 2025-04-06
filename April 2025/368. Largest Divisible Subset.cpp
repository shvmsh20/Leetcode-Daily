vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mx = 1;
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    dp[i] = max(dp[i], 1+dp[j]);
                    mx = max(mx, dp[i]);
                }
            }
        }
        vector<int> res;
        int prev = -1;
        for(int i=n-1; i>=0; i--){
            if(dp[i]==mx){
                if(prev==-1 || prev%nums[i]==0){
                    mx--;
                    res.push_back(nums[i]);
                    prev = nums[i];
                }
            }
        }
        return res;
    }