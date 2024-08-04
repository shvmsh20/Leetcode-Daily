int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> res;
        int mod = 1e9+7;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum = (sum+nums[j])%mod;
                res.push_back(sum);
            }
        }
        sort(res.begin(), res.end());
        int ans = 0;
        for(int i=left-1; i<=right-1; i++){
            ans = (ans+res[i])%mod;
        }
        return ans;
    }