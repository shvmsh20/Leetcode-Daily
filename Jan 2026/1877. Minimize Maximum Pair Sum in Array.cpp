int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int st = 0, lst = n-1, res = INT_MIN;
        while(st<lst){
            int currPSum = nums[st]+nums[lst];
            res = max(res, currPSum);
            st++;
            lst--;
        }
        return res;
    }