long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            nums[i]-=i;
            mp[nums[i]]++;
        }
        long long y=0;
        for(auto it: mp){
            long long x = it.second;
            y+= x*(x-1)/2;
        }
       
        long long tot = (long long) n*(n-1)/2;
        
        return tot-y;
        
    }