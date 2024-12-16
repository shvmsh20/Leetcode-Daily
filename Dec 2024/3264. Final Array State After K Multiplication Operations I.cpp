vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while(k--){
            int mn = INT_MAX, index = -1;
            for(int i=0; i<n; i++){
                if(nums[i]<mn){
                    mn = nums[i];
                    index = i;
                }
            }
            nums[index] = nums[index]*multiplier;
        } 
        return nums;
    }