int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        unordered_set<int> vis;
        int n = status.size();
        unordered_set<int> key;
        unordered_set<int> stock;
        queue<int> q;
        int res = 0;
        for(int u: initialBoxes){
            for(int i: keys[u]){
                key.insert(i);
            }
        }
        for(int u: initialBoxes){
            if(status[u]==1 || key.find(u)!=key.end()){
                vis.insert(u);
                q.push(u);
            }
            for(int i: containedBoxes[u]){
                stock.insert(i);
                if(vis.find(i)==vis.end() && (status[i]==1 || key.find(i)!=key.end())){
                    q.push(i);
                    vis.insert(i);
                }
            }
            for(int i: keys[u]){
                key.insert(i);
                if(stock.find(i)!=stock.end() && vis.find(i)==vis.end()){
                    q.push(i);
                    vis.insert(i);
                }
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            res+= candies[u];
            for(int i: containedBoxes[u]){
                stock.insert(i);
                if(vis.find(i)==vis.end() && (status[i]==1 || key.find(i)!=key.end())){
                    q.push(i);
                    vis.insert(i);
                }
            }
            for(int i: keys[u]){
                key.insert(i);
                if(stock.find(i)!=stock.end() && vis.find(i)==vis.end()){
                    q.push(i);
                    vis.insert(i);
                }
            }
        }
        return res;
    }