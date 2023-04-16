int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
            mp[nums[i]] = 1;
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && mp.find(nums[i]/nums[j])!=mp.end()){
                    int t1 = mp[nums[j]]%mod;
                    int t2 = (mp[nums[i]/nums[j]])%mod;
                    long long mul = (long long)t1*t2;
                    int ways = mul%mod;
                    
                    mp[nums[i]] = (mp[nums[i]] + ways)%mod;
                }
            }
        }
        int res = 0;
        for(int i=0; i<n; i++){
            res = (res + mp[nums[i]])%mod;
        }
        return res;
    }