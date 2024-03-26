int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int ele = nums[i];
           
            if(ele<=0 || ele>n){
                continue;
            }
             int chair = nums[i]-1;
            if(nums[chair]!=ele){
                swap(nums[i], nums[chair]);
                i--;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }