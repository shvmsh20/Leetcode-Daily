bool solve(int index, int n, vector<int> &nums, int curr, int sum, vector<vector<int>> &dp){
        if(curr==sum){
            return 1;
        }
        if(index==n){
            return 0;
        }
        if(dp[index][curr]!=-1){
            return dp[index][curr];
        }
        // not take
        bool res = solve(index+1, n, nums, curr, sum, dp);
        if(res){
            return dp[index][curr] = res;
        }
        // take
        if(curr+nums[index]<=sum){
            return dp[index][curr] = solve(index+1, n, nums, curr+nums[index], sum, dp);
        }
        return dp[index][curr] = 0;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int x: nums){
            sum+=x;
        }
        if(sum&1){
            return false;
        }
        sum/=2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solve(0, n, nums, 0, sum, dp);
    }