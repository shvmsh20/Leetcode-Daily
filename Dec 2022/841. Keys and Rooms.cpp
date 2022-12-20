bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        unordered_set<int> s;
        int cnt = 0, n = rooms.size();
        q.push(0);
        s.insert(0);
        while(!q.empty()){
            int room = q.front();
            q.pop();
            cnt++;
            for(int x: rooms[room]){
                if(s.find(x)==s.end()){
                    q.push(x);
                    s.insert(x);
                }
                   
            }
        }
        return cnt==n;
    }