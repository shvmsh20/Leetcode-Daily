int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        for(int i=0; i<n; i++){
            int nextIndex = (i+1)%n;
            res = max(res, abs(nums[i]-nums[nextIndex]));
        }
        return res;
    }