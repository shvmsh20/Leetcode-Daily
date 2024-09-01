vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        if(n*m!=size){
            return {};
        } 
        vector<vector<int>> res(m);
        for(int i=0; i<n*m; i+=n){
            int j=0;
            while(j<n){
                res[i/n].push_back(original[i+j]);
                j++;
            }
        }
        return res;
    }