int minOperations(vector<int>& nums) {
      int n=nums.size();
        int cnt=0;
        int i=2;
        while(i<n){
            if(nums[i-2]==0){
                nums[i-2]=!nums[i-2];
                nums[i-1]=!nums[i-1];
                nums[i]=!nums[i];
                cnt++;
            }
            i++;
        }
        for(auto it:nums)if(it==0)return -1;
        return cnt;  
    }