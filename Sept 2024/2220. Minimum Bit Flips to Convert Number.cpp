int minBitFlips(int start, int goal) {
        int res = 0;
        for(int i=0; i<31; i++){
            if((start&(1<<i)) != (goal&(1<<i))){
                res++;
            }
        }
        return res;
    }