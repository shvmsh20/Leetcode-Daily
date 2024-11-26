int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inEdges(n);
        for(vector<int> x: edges){
            inEdges[x[1]]++;
        }
        int res = -1, cnt = 0;
        for(int i=0; i<n; i++){
            if(inEdges[i]==0){
                cnt++;
                res = i;
            }
        }
        return cnt == 1 ? res : -1;
    }