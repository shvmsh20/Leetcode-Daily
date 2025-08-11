vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> v;
        for(int i=0; i<32; i++){
            if(n & (1<<i)){
                v.push_back(pow(2, i));
            }
        }
        int m = v.size();
        long long temp = 1;
        int mod = 1e9+7;
        
        vector<int> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];
            long long temp = 1;
            for(int j=left; j<=right; j++){
                temp = ((temp%mod)*(v[j]%mod))%mod;
            }
            ans[i] = temp;
        }
        return ans;
    }