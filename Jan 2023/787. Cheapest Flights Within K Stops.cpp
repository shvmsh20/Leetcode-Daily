int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> curr(n, INT_MAX);
        vector<int> temp(n, INT_MAX);
        curr[src] = 0;
        temp[src] = 0;
        k++;
        while(k--){
            for(vector<int> x: flights){
                if(curr[x[0]]==INT_MAX){
                    continue;
                }
                if(curr[x[0]]+x[2]<temp[x[1]]){
                    temp[x[1]] = curr[x[0]]+x[2];
                }
            }
            curr = temp;
        }
        return curr[dst]==INT_MAX?-1:curr[dst];
    }