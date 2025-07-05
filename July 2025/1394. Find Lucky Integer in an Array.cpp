int findLucky(vector<int>& arr) {
        vector<int> res(501);
        for(int x: arr){
            res[x]++;
        }
        for(int x=500; x>=1; x--){
            if(res[x]==x){
                return x;
            }
        }
        return -1;
    }