truct cmp{
        bool operator()(pair<long long, int> &p1, pair<long long, int> &p2){
            if(p1.first!=p2.first){
                return p1.first>p2.first;
            }
            return p1.second>p2.second;
        }
    };
    int mostBooked(int n, vector<vector<int>>& meetings) {
        unordered_map<int, int> mp;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, cmp> pq;
        priority_queue<int, vector<int>, greater<int>> unused;
        for(int i=0; i<n; i++){
            unused.push(i);
        }
        sort(meetings.begin(), meetings.end());
        for(int i=0; i<meetings.size(); i++){
            int st = meetings[i][0];
            int end = meetings[i][1];
            while(!pq.empty() && st>=pq.top().first){
                unused.push(pq.top().second);
                pq.pop();
            }
            if(!unused.empty()){
                int room = unused.top();
                unused.pop();
                mp[room]++;
                pq.push({end, room});
            }else{
                pair<long long, int> p = pq.top();
                pq.pop();
                mp[p.second]++;
                pq.push({p.first+end-st, p.second});
            }
            
        }
        int mx = 0, res = INT_MAX;
        for(auto x: mp){
            if(x.second>mx){
                res = x.first;
                mx = x.second;
            }else if(x.second==mx){
                res = min(res, x.first);
            }
        }
        return res;
    }