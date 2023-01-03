int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size(), cnt = 0;
        for(int i=0; i<m; i++){
            char last = 'a';
            for(int j=0; j<n; j++){
                if(strs[j][i]>=last){
                    last = strs[j][i];
                }else{
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }