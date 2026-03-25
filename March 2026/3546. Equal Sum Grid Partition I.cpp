bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<long> rows(n, 0), cols(m, 0);
        long rowsTotal = 0, colsTotal = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rows[i] = grid[i][j] + rows[i];
                cols[j] = grid[i][j] + cols[j];
            }
        }
        for(int i=0; i<n; i++){
            rowsTotal+= rows[i];
        }
        for(int j=0; j<m; j++){
            colsTotal+= cols[j];
        }
        if(rowsTotal%2!=0) return false;
        long reqTotal = rowsTotal/2, currTotal = 0;
        for(int i=0; i<n; i++){
            currTotal+= rows[i];
            if(currTotal==reqTotal){
                return true;
            }else if(currTotal>reqTotal){
                break;
            }
        }
        currTotal = 0;
         for(int j=0; j<m; j++){
            currTotal+= cols[j];
            if(currTotal==reqTotal){
                return true;
            }else if(currTotal>reqTotal){
                break;
            }
        }
        return false;
    }