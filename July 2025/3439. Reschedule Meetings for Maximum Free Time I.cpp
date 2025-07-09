int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> dist;
        dist.push_back(startTime[0]-0);
        for(int i=0; i<n-1; i++){
            dist.push_back(startTime[i+1]-endTime[i]);
        }
        dist.push_back(eventTime - endTime[n-1]);
        int res = 0;
        int m = dist.size();
        for(int i=0; i<m && i<=k; i++){
            res+= dist[i];
        }
        int ans = res;
        for(int i=k+1; i<m; i++){
            res-=dist[i-(k+1)];
            res+=dist[i];
            ans = max(ans, res);
        }
        return ans;
    }