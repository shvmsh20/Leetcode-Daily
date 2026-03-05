int minOperations(string s) {
        int n = s.size(), res1 = 0, res2 = 0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                if(s[i]=='1'){
                    res1++;
                }else{
                    res2++;
                }
            }else{
                if(s[i]=='0'){
                    res1++;
                }else{
                    res2++;
                }
            }
        }
        return min(res1, res2);
    }