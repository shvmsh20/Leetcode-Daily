int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int currPos = points[0][0];
        int res = 0;
        for(int i=1; i<points.size(); i++){
            res = max(res, points[i][0]-currPos);
            currPos = points[i][0];
        }
        return res;
    }