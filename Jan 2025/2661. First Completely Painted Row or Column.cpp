int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> mp;
        int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[mat[i][j]] = {i, j};
            }
        }
        vector<int> rows(n), cols(m);
        for(int i=0; i<n*m; i++){
            pair<int, int> p = mp[arr[i]];
            int x = p.first, y = p.second;
            rows[x]++;
            cols[y]++;
            if(rows[x]==m){
                return i;
            }
            if(cols[y]==n){
                return i;
            }
        }
        return -1;
    }