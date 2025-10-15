int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1), suff(n + 1);

        for (int i = 1; i <= n; i++) {
            if (i > 1 && nums[i - 2] < nums[i - 1]) pre[i] = pre[i - 1] + 1;
            else pre[i] = 1;
        }
        for (int i = n; i > 0; i--) {
            if (i < n && nums[i - 1] < nums[i]) suff[i] = suff[i + 1] + 1;
            else suff[i] = 1;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, min(pre[i - 1], suff[i]));
        }
        return ans;
    }