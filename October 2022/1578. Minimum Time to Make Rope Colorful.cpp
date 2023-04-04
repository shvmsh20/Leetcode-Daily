int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int res=0, i=0;
        while(i<n){
            int j=i+1, ans=neededTime[i], mx=neededTime[i];
            while(j<n){
                if(colors[i]==colors[j]){
                    ans+=neededTime[j];
                    mx = max(neededTime[j], mx);
                    j++;
                }
                else{
                    break;
                }
            }
            res += (ans-mx);
            i = j;
        }
        return res;
    }