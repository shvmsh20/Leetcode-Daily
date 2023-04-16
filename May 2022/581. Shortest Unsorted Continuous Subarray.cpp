int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0], mn = nums[n-1];
        int end = -1, st=0;
        for(int i=1; i<n; i++){
            if(nums[i]<mx){
                end = i;
            }else{
                mx = nums[i];
            }
        }
        for(int i=n-2; i>=0; i--){
            if(nums[i]>mn){
                st = i;
            }else{
                mn = nums[i];
            }
        }
        return end-st+1;
    }