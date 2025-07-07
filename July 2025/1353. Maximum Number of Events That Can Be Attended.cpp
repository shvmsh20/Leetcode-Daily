int maxEvents(vector<vector<int>>& events) {
       int n = events.size();
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int i=0, day=0, count=0;
        while(i<n || pq.empty()==false){
            if(pq.size()==0){
                day = events[i][0];
            }
            while(i<n && events[i][0]<=day){
                pq.push(events[i][1]);
                i++;
            }
            count++;
            day++;
            pq.pop();
            while(pq.empty()==false && pq.top()<day){
                pq.pop();
            }
        }
        return count;
    }