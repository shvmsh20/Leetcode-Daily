int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        for(int j=0; j<m; j++){
            int currOnes = 0;
            for(int i=0; i<n; i++){
                if(matrix[i][j]==1){
                    currOnes++;
                }else{
                    currOnes = 0;
                }
                v[i][j] = currOnes;
            }
        }
        for(int i=0; i<n; i++){
            sort(v[i].begin(), v[i].end(), greater<int>());
        }
        int res = 0;
        for(int i=0; i<n; i++){
            int mn = INT_MAX;
            for(int j=0; j<m && v[i][j]>0; j++){
                mn = min(mn, v[i][j]);
                res = max(res, mn*(j+1));
            }
        }
        return res;
    }