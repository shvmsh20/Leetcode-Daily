int find(int a, vector<int> &parent){
        if(a==parent[a]){
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
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26, 1);
        for(int i=0; i<26; i++){
            parent[i] = i;
        }
        for(string s: equations){
            char a = s[0];
            char b = s[3];
            if(s[1]=='='){
                int p1 = find(a-'a', parent);
                int p2 = find(b-'a', parent);
                if(p1!=p2){
                    Union(p1, p2, parent, rank);
                }
            }
        }
        for(string s: equations){
            char a = s[0];
            char b = s[3];
            if(s[1]=='!'){
                int p1 = find(a-'a', parent);
                int p2 = find(b-'a', parent);
                if(p1==p2){
                    return false;
                }
            }
        }
        return true;
    }