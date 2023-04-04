bool isPowerOfFour(int n) {
        return ((n&(n-1)==0) && (n&0xAAAA)==0); 
    }