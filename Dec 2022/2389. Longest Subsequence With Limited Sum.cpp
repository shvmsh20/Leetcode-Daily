vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++){
            nums[i]+=nums[i-1];
        }
        vector<int> res;
        for(int x: queries){
            int ans = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
            res.push_back(ans);
        }
        return res;
    }