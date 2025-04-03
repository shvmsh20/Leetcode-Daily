long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        vector<int> prefix(n), suffix(n);
        prefix[0] = -1;
        for(int i=1; i<n; i++){
            prefix[i] = max(prefix[i-1], nums[i-1]);
        }
        suffix[n-1] = -1;
        for(int i=n-2; i>=0; i--){
            suffix[i] = max(suffix[i+1], nums[i+1]);
        }
        for(int j=1; j<n-1; j++){
            res = max(res, (long long)suffix[j]*(prefix[j]-nums[j]));
        }
        return res;
    }