int countSubarrays(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i=1; i<n-1; i++){
            if(2*(nums[i-1]+nums[i+1])==nums[i]){
                res++;
            }
        }
        return res;
    }