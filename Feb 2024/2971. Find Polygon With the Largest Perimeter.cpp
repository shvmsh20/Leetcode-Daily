long long largestPerimeter(vector<int>& nums) {
        long long sum = 0;
        for(int x: nums){
            sum+=x;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=n-1; i>=2; i--){
            sum-=nums[i];
            if(sum>nums[i]){
                return nums[i]+sum;
            }
        }
        return -1;
    }