vector<vector<int>> generate(int n){
        vector<vector<int>> res(n);
        for(int i=0; i<n; i++){
            vector<int> ans(i+1);
            ans[0] = 1;
            ans[i] = 1;
            for(int j=1; j<i; j++){
                ans[j] = res[i-1][j-1]+res[i-1][j];
            }
            res[i] = ans;
        }
        return res;
    }