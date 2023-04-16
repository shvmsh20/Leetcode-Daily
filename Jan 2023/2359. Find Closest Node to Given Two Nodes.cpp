void dfs(int curr, int node, vector<int>& edges, vector<int> &dist){
        dist[node] = curr;
        if(edges[node]!=-1 && dist[edges[node]]==INT_MAX){
            dfs(curr+1, edges[node], edges, dist);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX);
        vector<int> dist2(n, INT_MAX);
        dfs(0, node1, edges, dist1);
        dfs(0, node2, edges, dist2);
        int val = INT_MAX, res = -1;
        for(int i=0; i<n; i++){
            int a = dist1[i];
            int b = dist2[i];
            int ans = max(a, b);
            if(ans<val){
                val = ans;
                res = i;
            }
        }
        return res;
        
    }