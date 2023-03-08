bool chck(long long limit, vector<int> &piles, int h){
        long long hours = 0;
        for(int i=0; i<piles.size(); i++){
            hours+= ceil((double)piles[i]/limit);
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long lo = 1, hi = 0, n = piles.size();
        for(int i=0; i<n; i++){
            hi = max(hi, (long long)piles[i]);
        }
        int res = -1;
        while(lo<=hi){
            long long mid = lo+(hi-lo)/2;
            if(chck(mid, piles, h)){
                res = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return res;
    }