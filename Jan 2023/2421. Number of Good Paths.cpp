int findParent(int a, vector<int> &parent){
        if(a==parent[a]){
            return a;
        }
        return parent[a] = findParent(parent[a], parent);
    }
    
   
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        
        vector<int> parent(n);
        map<int, int> count;    //max_element count
        map<int, int> max_ele;  //max_element in this subtree
        int res = n;
        for(int i=0; i<n; i++){
            parent[i] = i;
            max_ele[i] = vals[i];
            count[i]++;
        }
        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b){
            int x = max(vals[a[0]], vals[a[1]]);
            int y = max(vals[b[0]], vals[b[1]]);
            return x<y;
        });
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            //cout << a << " " << b << endl;
            a = findParent(a, parent);
            b = findParent(b, parent);
            
            if(max_ele[a]!=max_ele[b]){
                if(max_ele[a]>=max_ele[b]){
                    parent[b] = a;
                }else{
                    parent[a] = b;
                }
            }else{
                
                res+= count[a]*count[b];
                parent[b] = a;
                count[a]+=count[b];
            }
            
        }
        return res;
    }