static bool cmp(pair<int, int> &a, pair<int, int> &b){
        return a.first>b.first;
    }
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> dist;
        dist.push_back(startTime[0]-0);
        for(int i=0; i<n-1; i++){
            dist.push_back(startTime[i+1]-endTime[i]);
        }
        dist.push_back(eventTime - endTime[n-1]);
        int res = 0;
        vector<pair<int, int>> temp;
        int m = dist.size();
        for(int i=0; i<m; i++){
            temp.push_back({dist[i], i});
        }
        sort(temp.begin(), temp.end(), cmp);
        for(int i=0; i<n; i++){
            int st = startTime[i];
            int end = endTime[i];
            int prevEnd = -1, nextStart = -1;
            int prevDist = -1, nextDist = -1;
            if(i==0){
                prevEnd = 0;
            }
            if(i==n-1){
                nextStart = eventTime;
            }
            if(prevEnd==-1) prevEnd = endTime[i-1];
            if(nextStart==-1) nextStart = startTime[i+1];
           
            prevDist = st-prevEnd;
            
           
            nextDist = nextStart - end;
            
            // cout << prevDist << " " << nextDist << endl;
            // cout << prevEnd << " " << nextStart << endl;
            int ans = prevDist+nextDist;
            // cout << ans << endl;
            int dur = endTime[i]-startTime[i];
            bool found = false;
            for(int j=0; j<m; j++){
                pair<int, int> p = temp[j];
                if(p.first<dur){
                    break;
                }else{
                    if(p.second==i || p.second==(i+1)){
                        continue;
                    }else{
                        found = true;
                        break;
                    }
                }
            }
            // for(int i=0; i<m; i++){
            //     cout << temp[i].first << " " << temp[i].second << endl;
            // }
            // cout << ans << endl;
            if(found){
                ans+= dur;
            }
             // cout << ans << endl;
            res = max(res, ans);
        }
        return res;
    }