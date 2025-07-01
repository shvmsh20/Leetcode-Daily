int possibleStringCount(string word) {
        int n = word.size();
        int cnt = 0;
        char prev = '1';
        for(int i=0; i<n; i++){
            if(word[i]==prev){
                cnt++;
            }else{
                prev = word[i];
            }
        }
        return cnt+1;
    }