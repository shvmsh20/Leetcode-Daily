string maximumOddBinaryNumber(string s) {
        int cnt = 0, n = s.size();
            
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                cnt++;
            }
        }
        for(int i=0; i<n; i++){
            if(cnt>1){
                s[i] = '1';
                cnt--;
            }else{
                s[i] = '0';
            }
        }
        s[n-1] = '1';
        return s;
    }