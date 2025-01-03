int waysToSplitArray(vector<int>& nums) {
        long sum = 0, n = nums.size(), currSum = 0;
        int res = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        for(int i=0; i<n-1; i++){
            currSum+=nums[i];
            sum-=nums[i];
            if(currSum>=sum){
                res++;
            }
        }
        return res;
    }