int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]&1){
                nums[i] = 1;
            }else{
                nums[i] = 0;
            }
        }
        int prefixSum = 0, res = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i=0; i<n; i++){
            prefixSum+= nums[i];
            if(mp.find(prefixSum-k)!=mp.end()){
                res+= mp[prefixSum-k];
            }
            mp[prefixSum]++;
        }
        return res;
    }