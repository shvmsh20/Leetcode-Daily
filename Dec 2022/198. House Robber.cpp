int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int e2=nums[0], e1 = max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            int temp = max(nums[i]+e2, e1);
            e2 = e1;
            e1 = temp;
        }
        return e1;
        
    } 