 vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        long long sum=0, sq=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
            sq+=(nums[i]*nums[i]);
        }
        long long p = sum-(n*(n+1)/2);
        long long q = sq - (long long)n*(n+1)*(2*n+1)/6;
        res[0] = ((q/p)+p)/2;
        res[1] = res[0]-p;
        return res;
    }