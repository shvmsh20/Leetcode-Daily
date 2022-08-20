int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size(), count=0, index=0;
        priority_queue<int> pq;
        int mx_reach = startFuel;
        while(mx_reach<target){
            while(index<n && stations[index][0]<=mx_reach){
                pq.push(stations[index][1]);
                index++;
            }
            if(pq.empty()){
                return -1;
            }
            mx_reach+= pq.top();
            pq.pop();
            count++;
        }
        return count;
        
    }