long long distributeCandies(int n, int limit) {
        long long res = 0;
        for(int i=0; i<=min(n, limit); i++){
            int rem = n - i;
            if(rem>2*limit) continue;
            int j = max(0, rem-limit), k = min(rem, limit);
            res+= k-j+1;
        }
        return res;
    }