int findMaxK(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        int res = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]>0 && mp.find(-1*nums[i])!=mp.end()){
                res = max(res, nums[i]);
            }
        }
        return res==INT_MIN?-1:res;
    }