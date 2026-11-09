vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        vector<int> freq(k, 0);
        int maxReq = 0;
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        for (int i = 0; i < arrival.size(); ++i) {
            while (!pq.empty() && pq.top().first <= arrival[i]) {
                available.insert(pq.top().second);
                pq.pop();
            }
            if (available.empty()) continue;
            auto it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin();
            }
            int server = *it;
            available.erase(it);
            pq.push({(long long)arrival[i] + load[i], server});
            freq[server]++;
            maxReq = max(maxReq, freq[server]);
        }
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            if (freq[i] == maxReq) {
                res.push_back(i);
            }
        }

        return res;
    }