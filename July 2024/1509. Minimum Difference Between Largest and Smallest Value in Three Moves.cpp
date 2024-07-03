int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int r1 = nums[n-1]-nums[3], r2 = nums[n-2]-nums[2], r3 = nums[n-3]-nums[1], r4 = nums[n-4]-nums[0];
        return min(r4,(min(r3, min(r1, r2))));
    }