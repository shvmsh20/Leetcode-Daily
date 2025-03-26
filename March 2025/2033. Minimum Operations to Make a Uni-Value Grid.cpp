int minOperations(vector<vector<int>>& grid, int x) {
       vector<int> arr;
       int n = grid.size(), m = grid[0].size();
       int rem = -1;
       int totalSum = 0;
       for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr.push_back(grid[i][j]);
            totalSum+= grid[i][j];
            if(rem == -1){
                rem = grid[i][j]%x;
            }else {
                if(rem!=grid[i][j]%x){
                    return -1;
                }
            }
        }
       }
       sort(arr.begin(), arr.end());
       n = n*m;
       int prefixSum = 0;
       int res = INT_MAX;
       for(int i=0; i<n; i++){
        int leftCnt = ((i*arr[i])-prefixSum)/x;
        int rightCnt = ((totalSum-prefixSum) - ((n-i)*arr[i]) )/x;
        // cout << leftCnt << " " << rightCnt << endl;
        prefixSum+= arr[i];
        res = min(res, leftCnt+rightCnt);
       }
       return res;
    }