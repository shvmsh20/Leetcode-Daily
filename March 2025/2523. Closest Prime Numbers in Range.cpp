vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right+1, true);
        isPrime[1] = false;
        for(int i=2; i*i<=right; i++){
            for(int j=i*i; j<=right; j+=i){
                isPrime[j] = false;
            }
        }
        int prev = -1;
        int res = INT_MAX;
        vector<int> ans = {-1, -1};
        for(int i=left; i<=right; i++){
            if(isPrime[i]){
                if(prev!=-1){
                   int diff = i-prev;
                   if(res>diff){
                        ans[0] = prev;
                        ans[1] = i;
                        res = diff;
                   }
                }
                prev = i;
            }
        }
        
        return ans;
    }