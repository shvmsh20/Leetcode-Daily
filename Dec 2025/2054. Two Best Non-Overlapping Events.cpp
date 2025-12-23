int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> vec;
        for(vector<int> x: events){
            vec.push_back({x[0], 1, x[2]});
            vec.push_back({x[1]+1, -1, x[2]});
        }
        sort(vec.begin(), vec.end());
        int res = 0;
        int currMx = 0;
        for(vector<int> x: vec){
            if(x[1]==1){
                res = max(res, x[2]+currMx);
            }else{
                currMx = max(currMx, x[2]);
            }
        }
        return res;
    }