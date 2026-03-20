vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n-k+1, vector<int>(m-k+1));
        vector<int> temp(k*k);
        for(int i=0; i<n-k+1; i++){
            for(int j=0; j<m-k+1; j++){
                int index = 0;
                for(int x=i; x<i+k; x++){
                    for(int y=j; y<j+k; y++){
                        temp[index++] = grid[x][y];
                    }
                }
                sort(temp.begin(), temp.end());
                int ans = INT_MAX;
                for(int l=0; l<k*k-1; l++){
                    if(temp[l]==temp[l+1]) continue;
                    ans = min(ans, abs(temp[l]-temp[l+1]));
                }
                res[i][j] = ans==INT_MAX?0: ans;
            }
        }
        return res;
    }