void dfs(int currtime, int u, vector<int> &edges, vector<int> &time, vector<bool> &inStack, int &res){
        inStack[u] = true;
        time[u] = currtime;
        int v = edges[u];
        if(v==-1){
            inStack[u] = false;
            return;
        }
        if(time[v]==-1){
            dfs(currtime+1, v, edges, time, inStack, res);
        }else if(inStack[v]){
            res = max(res, currtime-time[v]+1);
        }
        inStack[u] = false;
        
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> inStack(n, false); 
        int res = -1;
        vector<int> time(n, -1);
        for(int i=0; i<n; i++){
            if(time[i]==-1){
                dfs(1, i, edges, time, inStack, res);
            }
        }
        return res;
    }