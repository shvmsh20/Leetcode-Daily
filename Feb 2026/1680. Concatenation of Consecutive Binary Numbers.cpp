int countBits(int n){
        for(int i=31; i>=0; i--){
            if(n & (1<<i)){
                return i+1;
            }
        }
        return 0;
    }
    int concatenatedBinary(int n) {
        int mod = 1e9+7;
        long pow2 = 1, prev = 0, res = 0;
        while(n){
            for(int i=0; i<prev; i++){
                pow2 = (2*pow2)%mod;
            }
            res = ((res%mod) + (n*pow2)%mod)%mod;
            prev = countBits(n);
            n--;
        }
        return res;
    }