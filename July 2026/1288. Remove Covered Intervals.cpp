static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }
        return a[1]>b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0][0], end = intervals[0][1], res = 0;
        for(int i=1; i<n; i++){
            if(start<=intervals[i][0] && end>=intervals[i][1]){
                continue;
            }else{
                res++;
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        res++;
        return res;
    }