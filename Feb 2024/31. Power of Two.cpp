bool isPowerOfTwo(int n) {
        int cnt = 0;
        if(n<0){
            return false;
        }
        for(int i=0; i<31; i++){
            if(n&(1<<i)){
                cnt++;
            }
        }
        if(cnt==1){
            return true;
        }else{
            return false;
        }
    }