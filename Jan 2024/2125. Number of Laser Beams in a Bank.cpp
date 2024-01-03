int numberOfBeams(vector<string>& bank) {
        int n = bank.size(), m = bank[0].size();
        int prevCnt = 0, currCnt = 0, res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(bank[i][j]=='1'){
                    currCnt++;
                }
            }
            if(currCnt!=0){
                res+= currCnt*prevCnt;
                prevCnt = currCnt;
                currCnt = 0;
            }
        }
        return res;
    }