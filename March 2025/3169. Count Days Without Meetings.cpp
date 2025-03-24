int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> merged;
        sort(meetings.begin(), meetings.end());
        vector<int> curr = meetings[0];
        int n = meetings.size();
        for(int i=1; i<n; i++){
            if(meetings[i][0]>curr[1]){
                merged.push_back(curr);
                curr = meetings[i];
            }else{
                curr[1] = max(curr[1], meetings[i][1]); 
            }
        }
        merged.push_back(curr);
        int res = 0, last = 0;
        for(vector<int> x: merged){
            res+= x[0]-last-1;
            last = x[1];
        }
        res+= (days-last);
        return res;
    }