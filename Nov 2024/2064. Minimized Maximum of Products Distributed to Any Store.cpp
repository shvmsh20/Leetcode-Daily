bool isPoss(long x, int n, vector<int> arr, long chck){
        long cnt = 0;
        for(int i=0; i<n; i++){
            cnt += arr[i]/x;
            cnt+= arr[i]%x ? 1: 0;
        }
        if(cnt<=chck){
            return true;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int m = q.size();
        long lo = 1, hi = 0;
        for(int i=0; i<m; i++){
            hi+= q[i];
        }

        int res = 0;
        while(lo<=hi){
            long mid = lo+(hi-lo)/2;
            if(isPoss(mid, m, q, n)){
                res = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return res;
    }