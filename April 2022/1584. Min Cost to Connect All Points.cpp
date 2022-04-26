int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> edges;
        int n = points.size();
        
        vector<vector<pair<int, int>>> adj_list(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1=points[i][0], x2=points[j][0];
                int y1=points[i][1], y2=points[j][1];
                int m_dist = abs(x1-x2)+abs(y1-y2);
                adj_list[i].push_back({j, m_dist});
                adj_list[j].push_back({i, m_dist});
            }
        }
        
        vector<bool> visited(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, 0});
        
        int res=0;
        
        for(int i=0; i<n; i++){
            pair<int, int> p = pq.top();
            pq.pop();
            int u = p.second;
            if(visited[u]){
                i--;
                continue;
            }
            visited[u] = true;
            res+= p.first;
            for(auto x: adj_list[u]){
                int v = x.first;
                if(visited[v]==false){
                    pq.push({x.second, v});
                }
            }
        }
        
        return res;
    }