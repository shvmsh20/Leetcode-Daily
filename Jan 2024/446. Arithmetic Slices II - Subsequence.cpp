int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long  res = 0;
        vector<unordered_map<long long  , long long  >> dp(n);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                long long  diff =( long long)nums[i]- (long long)nums[j];
                dp[i][diff]++;
                if(dp[j].find(diff)!=dp[j].end()){
                    dp[i][diff]+= dp[j][diff];
                    res+= dp[j][diff];
                }
            }
        }
        return res;
    }