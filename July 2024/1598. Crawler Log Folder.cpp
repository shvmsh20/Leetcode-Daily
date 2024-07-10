int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(string x: logs){
            if(x[0]=='.' && x[1]=='.'){
                if(cnt!=0){
                    cnt--;
                }
            }else if(x[0]=='.'){
                continue;
            }else{
                cnt++;
            }
        }
        return cnt;
    }