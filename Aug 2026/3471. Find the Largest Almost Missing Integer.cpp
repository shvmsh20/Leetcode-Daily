int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int res = -1;
        unordered_map<int, int> mp;
        if(n<k){
            return -1;
        }
        for(int i=0; i<=n-k; i++){
            unordered_set<int> s;
            for(int j=i; j<i+k; j++){
                s.insert(nums[j]);
            }
            for(int x: s){
                mp[x]++;
            }
        }
        for(auto x: mp){
            if(x.second==1){
                res = max(res, x.first);
            }
        }
        return res;
    }