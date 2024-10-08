int minSwaps(string s) {
        int cnt = 0, res = 0;
        for(char x: s){
            if(x=='['){
                cnt--;
            }else{
                cnt++;
            }
            res = max(res, cnt);
        }
        return (res+1)/2;
    }