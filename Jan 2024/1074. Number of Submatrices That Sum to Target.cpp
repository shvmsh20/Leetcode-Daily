int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                matrix[i][j]+= matrix[i][j-1];
            }
        }
        int count=0;
        unordered_map<int, int> mp;
        for(int start=0; start<m; start++){
            for(int j=start; j<m; j++){
                mp.clear();
                mp[0]=1;
                int curr=0;
                for(int k=0; k<n; k++){
                    curr+= matrix[k][j] - (start>=1?matrix[k][start-1]:0);
                    if(mp.find(curr-target)!=mp.end()){
                        count+= mp[curr-target];
                    }
                    mp[curr]++;
                }
            }
        }
        return count;
    }