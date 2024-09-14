int longestSubarray(vector<int>& nums) {
        int mx = INT_MIN;
        int res = 1;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(mx<nums[i]){
                mx = nums[i];
                count=1;
                res = 1;
            }else if(mx==nums[i] && nums[i-1]==nums[i]){
                count++;
                res = max(count, res);
            }else{
                count = 1;
            }
        }
        return res;
    }