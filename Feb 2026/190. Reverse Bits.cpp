int reverseBits(int n) {
        int res = 0;
        for(int i=0; i<32; i++){
            if(n & (1<<i)){
                res = res | (1<<(31-i));
            }
        }
        return res;
    }