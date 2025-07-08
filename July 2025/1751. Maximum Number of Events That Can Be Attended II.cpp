int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());

        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        vector<int> startTimes;
        for (auto& e : events) startTimes.push_back(e[0]);

        for (int i = n - 1; i >= 0; --i) {
            int next = lower_bound(startTimes.begin(), startTimes.end(), events[i][1] + 1) - startTimes.begin();
            for (int j = 1; j <= k; ++j) {
                int include = events[i][2] + dp[next][j - 1];
                int exclude = dp[i + 1][j];
                dp[i][j] = max(include, exclude);
            }
        }
        return dp[0][k];
    }