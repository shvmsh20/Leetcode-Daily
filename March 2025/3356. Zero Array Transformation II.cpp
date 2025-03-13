bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            prefix[l] += val;
            if (r + 1 < n) {
                prefix[r + 1] -= val;
            }
        }

        for (int i = 1; i <= n; i++) {
            prefix[i] += prefix[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (prefix[i] < nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0, high = queries.size(), n = queries.size(), ans = n + 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isZeroArray(nums, queries, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (ans > n) ? -1 : ans;
    }