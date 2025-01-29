int findParent(int x, vector<int> &par){
        if(par[x]==x){
            return x;
        }
        return par[x] = findParent(par[x], par);
    }
    void Union(int a, int b, vector<int> &parent, vector<int> &size){
        if(size[a]<size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a]+= size[b];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> size(n+1, 1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        for(vector<int> x: edges){
            int a = x[0];
            int b = x[1];
            int p1 = findParent(a, parent);
            int p2 = findParent(b, parent);
            if(p1==p2){
                return x;
            }else{
                Union(p1, p2, parent, size);
            }
        }
        return {-1, -1};
    }