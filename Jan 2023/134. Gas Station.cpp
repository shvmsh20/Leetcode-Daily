int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasTot = 0, costTot=0, tot=0, n = cost.size(), res=0;
        for(int i=0; i<n; i++){
            gasTot+= gas[i];
            costTot+= cost[i];
        }
        if(costTot>gasTot){
            return -1;
        }
        for(int i=0; i<n; i++){
            tot+= gas[i]-cost[i];
            if(tot<0){
                tot=0;
                res = i+1;
            }
        }
        return res;
    }