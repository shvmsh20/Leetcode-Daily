 int find(int a, vector<int> &parent){
        int p = parent[a];
        while(parent[p]!=p){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    void Union(int a, int b, vector<int> &parent, vector<int> &rank){
        if(rank[a]<rank[b]){
            swap(a, b);
        }
        parent[b] = a;
        rank[a]+= rank[b];
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int provinces=adj.size();
        int n = adj.size();
        vector<int> parent(n);
        vector<int> rank(n,1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(adj[i][j]==1 && i!=j){
                    
                    int p1 = find(i, parent);
                    int p2 = find(j, parent);
                    if(p1!=p2){
                        Union(p1, p2, parent, rank);
                        provinces--;
                    }
                }
            }
        }
        
        
        return provinces;
    }