int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<2){
            return 1;
        }
        int res = 0;
        for(int i=0; i<n; i++){
            unordered_map<float, int> mp;
            int mx = 0;
            for(int j=i+1; j<n; j++){
                float slope;
                if(points[j][0]-points[i][0]==0){
                    slope = 1000000001;
                }else{
                    slope = (float)(points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                }
                mp[slope]++;
                mx = max(mx, mp[slope]);
            }
            res = max(res, mx);
        }
        return res+1;
    }