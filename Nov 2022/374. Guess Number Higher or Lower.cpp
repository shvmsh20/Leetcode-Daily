int lo = 1, hi;
    int guessNumber(int n) {
        hi = n;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int t = guess(mid);
            if(t==-1){
                hi = mid-1;
            }else if(t==1){
                lo = mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }