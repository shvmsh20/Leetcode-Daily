vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rowMin(n);
        vector<int> colMax(m);
        for(int i=0; i<n; i++){
            int mn = INT_MAX;
            for(int j=0; j<m; j++){
                mn = min(mn, matrix[i][j]);
            }
            rowMin[i] = mn;
        }
        for(int j=0; j<m; j++){
            int mx = INT_MIN;
            for(int i=0; i<n; i++){
                mx = max(mx, matrix[i][j]);
            }
            colMax[j] = mx;
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(rowMin[i]==matrix[i][j] && colMax[j]==matrix[i][j]){
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }