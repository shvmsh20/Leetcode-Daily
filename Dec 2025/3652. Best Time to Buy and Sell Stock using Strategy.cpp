long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
         int half = k/2;
        int n = prices.size();

        vector<long long> ori;

        long long val = 0;
        for(int i=0;i<n;i++)
        {
            val = val + 1LL * prices[i] * strategy[i];
            ori.push_back(val);
        }

        long long maxi = val;

        vector<long long> pos;

        val = 0;
        for(int i=0; i<n;i++)
        {
            val = val + 1LL * prices[i];
            pos.push_back(val);
        }

        for(int i=k-1;i<n;i++)
        {
            int l = i - k + 1;
            int mid = i - half;

            long long sumOri = ori[i] - (l-1>=0 ? ori[l-1] : 0LL);
            long long sumSecond = pos[i] - pos[mid];

            long long cur = ori.back() - sumOri + sumSecond;

            maxi = max(maxi, cur);
        }

        return maxi;
    }