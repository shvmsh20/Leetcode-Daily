int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int currX = points[0][0];
        int currY = points[0][1];
        int res = 0;
        for(int i=1; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int xDiff = abs(currX-x);
            int yDiff = abs(currY-y);
            int mn = min(xDiff, yDiff);
            res+= ((xDiff-mn) + (yDiff-mn) + mn);
            currX = x;
            currY = y;
        }
        return res;
    }