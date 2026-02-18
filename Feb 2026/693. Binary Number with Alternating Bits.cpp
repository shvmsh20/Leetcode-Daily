bool hasAlternatingBits(int n) {
        bool lastBitSetOrNot = false;
        int i=31;
        while(i>=0 && ((n&(1<<i))==0)){
            i--;
        }
        lastBitSetOrNot = true;
        i--;
        for(; i>=0; i--){
            bool currBitSetOrNot = n&(1<<i) ? true : false;
            if(lastBitSetOrNot == currBitSetOrNot){
                return false;
            }
            lastBitSetOrNot = currBitSetOrNot;
        }
        return true;
    }