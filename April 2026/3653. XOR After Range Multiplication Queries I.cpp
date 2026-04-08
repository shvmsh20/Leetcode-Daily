int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto x: queries){
            int l = x[0], r = x[1], k = x[2], v = x[3];
             while(l<=r){
                long newVal = (long)nums[l] * v;
                nums[l] = newVal % mod;
                l+= k;
             }
        }
        int res = 0;
        for(int x: nums){
            res = res ^ x;
        }
        return res;
    }