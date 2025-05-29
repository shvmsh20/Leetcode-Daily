vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1, m = edges2.size()+1;
        vector<vector<int>> adj1(n);
        for(vector<int> x: edges1){
            adj1[x[0]].push_back(x[1]);
            adj1[x[1]].push_back(x[0]);
        }
        vector<vector<int>> adj2(m);
        vector<int> res;
        for(vector<int> x: edges2){
            adj2[x[0]].push_back(x[1]);
            adj2[x[1]].push_back(x[0]);
        }
        int evenCnt = 0;
        queue<vector<int>> q;
        q.push({0, -1});
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            if(level%2==0){
                evenCnt+=sz;
            }
            while(sz--){
                vector<int> p = q.front();
                q.pop();
                for(int v: adj2[p[0]]){
                    if(v!=p[1]){
                        q.push({v, p[0]});
                    }
                }
            }
            level++;
        }
        int mxTree2 = max(evenCnt, m-evenCnt);
        evenCnt = 0;
        vector<bool> evenPos(n, false);
        q.push({0, -1});
        level = 0;
        while(!q.empty()){
            int sz = q.size();
            if(level%2==0){
                evenCnt+=sz;
            }
            while(sz--){
                vector<int> p = q.front();
                q.pop();
                if(level%2==0){
                    evenPos[p[0]] = true;
                }
                for(int v: adj1[p[0]]){
                    if(v!=p[1]){
                        q.push({v, p[0]});
                    }
                }
            }
            level++;
        }
        // cout << mxTree2 << endl;
        int oddCnt = n-evenCnt;
      
        for(int i=0; i<n; i++){
            if(evenPos[i]){
                res.push_back(mxTree2+evenCnt);
            }else{
                res.push_back(oddCnt+mxTree2);
            }
        }
        return res;
    }