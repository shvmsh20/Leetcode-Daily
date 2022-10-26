bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int prefix=0, n=nums.size();
        for(int i=0; i<n; i++){
            prefix+= nums[i];
            int rem = prefix%k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2){
                    return true;
                }
            }else{
                mp[rem] = i;
            }
            
        }
        return false;
    }