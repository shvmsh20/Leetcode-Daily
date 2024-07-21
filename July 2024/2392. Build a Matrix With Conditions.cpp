bool topoSort(vector<vector<int>> &graph, vector<int> &v, int n){
        vector<int> inDeg(n);
        for(auto x: graph){
            for(int y: x){
                inDeg[y]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int u = q.front();
            v.push_back(u);
            q.pop();
            count++;
            for(int v: graph[u]){
                inDeg[v]--;
                if(inDeg[v]==0){
                    q.push(v);
                }
            }
        }
        if(count!=n){
            return false;
        }else{
            return true;
        }
        
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> res(k, vector<int>(k));
        vector<vector<int>> graph1(k);
        vector<vector<int>> graph2(k);
        for(auto x: rowConditions){
            int u = x[0]-1;
            int v = x[1]-1;
            graph1[u].push_back(v);
        }
        for(auto x: colConditions){
            int u = x[0]-1;
            int v = x[1]-1;
            graph2[u].push_back(v);
        }
        vector<int> v1, v2;
        vector<vector<int>> temp;
        if(topoSort(graph1, v1, k)==false){
            
            return temp;
        }
        if(topoSort(graph2, v2, k)==false){
            return temp;
        }
        unordered_map<int, int> mp;
        for(int i=0; i<k; i++){
            mp[v2[i]] = i;
        }
        for(int i=0; i<k; i++){
            res[i][mp[v1[i]]] = v1[i]+1;
        }
        // for(int x: v1){
        //     cout << x << " ";
        // }
        // cout << endl;
        // for(int x: v2){
        //     cout << x << " ";
        // }
        return res;
    }