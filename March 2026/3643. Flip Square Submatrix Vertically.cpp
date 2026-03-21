vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int l = x, h = x+k-1;
        while(l<h){
            for(int j=y; j<y+k; j++){
                swap(grid[l][j], grid[h][j]);
            }
            l++;
            h--;
        }
        return grid;
    }