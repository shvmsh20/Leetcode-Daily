vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> res(2);
        int n = grid.size();
        int xr = 0;
        for(int i=0; i<n*n; i++){
            int row = i/n;
            int col = i%n;
            xr = xr ^ grid[row][col];
            xr = xr ^ (i+1);
        }
        int lastSetBit = xr & (~(xr-1));
        int b1 = 0, b2 = 0, cnt = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] & lastSetBit){
                    b1 = b1 ^ grid[i][j];
                }else{
                    b2 = b2 ^ grid[i][j];
                }
                if(cnt & lastSetBit){
                    b1 = b1 ^ cnt;
                }else{
                    b2 = b2 ^ cnt;
                }
                cnt++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(b1==grid[i][j]){
                    return {b1, b2};
                }
            }
        }
        return {b2, b1};
    }