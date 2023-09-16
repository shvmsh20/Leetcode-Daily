int minimumEffortPath(vector<vector<int>>& heights) {
         int n = heights.size(), m = heights[0].size();
        vector<vector<int>> effort(n, vector<int> (m, INT_MAX));
        priority_queue< pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        pq.push({0, {0,0}});
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int dist = x.first;
            int row = x.second.first;
            int col = x.second.second;
            
            if(dist>effort[row][col]){
                continue;
            }
            if(row==n-1  && col==m-1){
                return dist;
            }
            for(auto d: dir){
                int newRow = row+d[0];
                int newCol = col+d[1];
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m){
                    int newDist = max(dist, abs(heights[row][col]-heights[newRow][newCol]));
                    if(newDist<effort[newRow][newCol]){
                        effort[newRow][newCol] = newDist;
                        pq.push({newDist, {newRow, newCol}});
                    }
                }
            }
        }
        return 0;
    }