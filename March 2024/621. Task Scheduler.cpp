int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(char x: tasks){
            mp[x]++;
        }
        priority_queue<int> pq;
        for(pair<char, int> p: mp){
            pq.push(p.second);
        }
        queue<pair<int, int>> q; // <freq, availableTime>
        int time  = 0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();
                if(freq!=1){
                    q.push({freq-1, time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                pair<int, int> p = q.front();
                q.pop();
                
                pq.push(p.first);
                
            }
        }
        return time;
    }