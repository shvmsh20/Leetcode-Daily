vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int key = i-j;
                mp[key].push(mat[i][j]);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int key = i-j;
                mat[i][j] = mp[key].top();
                mp[key].pop();
            }
        }
        return mat;
    }