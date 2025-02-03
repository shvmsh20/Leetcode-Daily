int longestMonotonicSubarray(vector<int>& nums) {
        int prev = nums[0], res = 1;
        int currInc = 1, currDesc = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>prev){
                currInc++;
            }else{
                currInc = 1;
            }
            if(nums[i]<prev){
                currDesc++;
            }else{
                currDesc = 1;
            }
            prev = nums[i];
            res = max(res, max(currInc, currDesc));
        }
        return res;
    }