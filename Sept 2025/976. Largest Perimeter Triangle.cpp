int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i+2<n){
                if(nums[i+1]+nums[i+2]>nums[i]){
                    return nums[i+1]+nums[i+2]+nums[i];
                }
            }
        }
        return 0;
    }