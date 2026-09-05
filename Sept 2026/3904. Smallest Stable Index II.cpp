int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();

        vector<int> minVal(n);
        minVal[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++) {
            minVal[n - i - 1] = min(
                nums[n - i - 1],
                minVal[n - i]
            );
        }

        int maxVal = nums[0];

        for(int i = 0; i < n; i++) {
            maxVal = max(nums[i], maxVal);

            int diff = maxVal - minVal[i];

            if(diff <= k) {
                return i;
            }
        }

        return -1;
    }