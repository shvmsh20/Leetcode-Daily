bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        if(n==1){
            return false;
        }
        for(int i=0; i<n && i<=k; i++){
            mp[nums[i]]++;
        }
        
        for(int i=k+1; i<n; i++){
            if(mp.size()<k+1){
                return true;
            }
            mp[nums[i]]++;
            mp[nums[i-k-1]]--;
            if(mp[nums[i-k-1]]==0){
                mp.erase(nums[i-k-1]);
            }
        }
        
        return mp.size()<min(k+1, n);
    }