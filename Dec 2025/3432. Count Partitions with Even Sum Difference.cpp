int countPartitions(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            total+= nums[i];
        }
        int res = 0;
        int left = 0;
        for(int i=0; i<n-1; i++){
            left+= nums[i];
            total-=nums[i];
            if(abs(left-total)%2==0){
                res++;
            }
        }
        return res;
    }