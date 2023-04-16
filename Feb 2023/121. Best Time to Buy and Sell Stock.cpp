int maxProfit(vector<int>& nums) {
        int res = 0;
        int currMin = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<currMin){
                currMin = nums[i];
            }else{
                res = max(res, nums[i]-currMin);
            }
        }
        return res;
    }