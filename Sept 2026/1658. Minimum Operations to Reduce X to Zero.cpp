int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int s=0, e=0;
        long long sum=0;
        for(int x: nums){
            sum+=x;
        }
        if(sum==x){
            return n;
        }
        long long target = sum-x;
        int res=0;
        sum=0;
        while(e<n){
            sum+=nums[e];
            while(s<e && sum>target){
                sum-=nums[s];
                s++;
            }
            if(sum==target){
                res = max(res, e-s+1);
            }
            e++;
        }
        return res==0?-1:n-res;
    }