struct Node{
        int wt;
        int u;
        int v;
        Node(int wt, int u, int v){
            this->wt = wt;
            this->u = u;
            this->v = v;
        }
    };
    static bool cmp(Node a, Node b){
        return a.wt<b.wt;
    }
    int find(int a, vector<int> &parent){
        if(parent[a]==a){
            return a;
        }
        return parent[a] = find(parent[a], parent);
    }
    void Union(int p1, int p2, vector<int> &parent, vector<int> &rank){
        if(rank[p1]<rank[p2]){
            swap(p1, p2);
        }
        parent[p2] = p1;
        rank[p1]+=rank[p2];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res=0;
        vector<Node> ed;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                ed.push_back(Node(dist, i, j));
            }
        }
        sort(ed.begin(), ed.end(), cmp);
        vector<int> parent(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        vector<int> rank(n, 1);
        for(int i=0; i<ed.size(); i++){
            int wt = ed[i].wt;
            int u = ed[i].u;
            int v = ed[i].v;
            int p1 = find(u, parent);
            int p2 = find(v, parent);
           
            if(p1!=p2){
                res+=wt;
    
                Union(p1, p2, parent, rank);
            }
        }
        return res;
    }