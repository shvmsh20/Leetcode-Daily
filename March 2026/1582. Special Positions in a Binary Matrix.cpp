int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> rowsCnt(n, 0), colsCnt(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1){
                    rowsCnt[i]++;
                    colsCnt[j]++;
                }
            }
        }
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1 && rowsCnt[i]==1 && colsCnt[j]==1){
                    res++;
                }
            }
        }
        return res;
    }