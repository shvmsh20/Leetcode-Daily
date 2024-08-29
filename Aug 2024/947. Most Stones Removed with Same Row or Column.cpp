class DisjointSet{
    vector<int> size, parent;
    public:
        DisjointSet(int n){
            size.resize(n);
            parent.resize(n);
            for(int i=0; i<n; i++){
                size[i] = 1;
                parent[i] = i;
            }
        }
        int findParent(int a){
            if(parent[a]==a){
                return a;
            }
            return parent[a] = findParent(parent[a]);
        }
        void Union(int a, int b){
            a = findParent(a);
            b = findParent(b);
            if(a==b){
                return;
            }
            if(size[a]<size[b]){
                swap(a, b);
            }
            parent[b] = a;
            size[a]+=size[b];
        }
};
class Solution {
public:

    int removeStones(vector<vector<int>>& stones) {
        int mxRow = 0, mxCol = 0;
        unordered_map<int, int> posMp;
        for(auto x: stones){
            mxRow = max(mxRow, x[0]);
            mxCol = max(mxCol, x[1]);
        }
        DisjointSet ds(mxRow+2+mxCol);
        for(auto x: stones){
            int row = x[0];
            int col = x[1]+mxRow+1;
            posMp[row] = 1;
            posMp[col] = 1;
            ds.Union(row, col);
        }
        int count=0;
        for(auto x: posMp){
            if(ds.findParent(x.first)==x.first){
                count++;
            }
        }
        return stones.size()-count;
    }
};