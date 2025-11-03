int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int lstColor = colors[0];
        int mx = neededTime[0], sum = neededTime[0], res = 0;
        for(int i=1; i<n; i++){
            if(lstColor==colors[i]){
                sum+= neededTime[i];
                mx = max(mx, neededTime[i]);
            }else{
                if(mx != INT_MIN){
                    res+= (sum-mx);
                }
                mx = neededTime[i];
                sum = neededTime[i];
                lstColor = colors[i];
            }
        }
        if(mx!=INT_MIN){
            res+= (sum-mx);
        }
        return res;
    }