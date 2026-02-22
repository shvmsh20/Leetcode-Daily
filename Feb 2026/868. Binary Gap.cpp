int binaryGap(int n) {
        int prevPos = -1, res = -1;
        for(int i=0; i<32; i++){
            if(n & (1<<i)){
                if(prevPos!=-1){
                    res = max(res, i-prevPos);
                }
                prevPos = i;
            }
        }
        return res==-1?0:res;
    }