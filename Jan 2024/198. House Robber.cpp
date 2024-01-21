int solve(int index, int n, vector<int> &nums, vector<int> &dp){
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        return dp[index] = max(nums[index]+solve(index+2, n, nums, dp), solve(index+1, n, nums, dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, n, nums, dp);
    }