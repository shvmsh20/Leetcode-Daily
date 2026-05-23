bool check(vector<int>& nums) {
       int n = nums.size();
       int index = 0;
       for(int i=1; i<n; i++){
        if(nums[i]<=nums[index] && nums[i]!=nums[i-1]){
            index = i;
        }
       }
       int prev = -1, m = n;
       while(m--){
        if(prev>nums[index]){
            return false;
        }
        prev = nums[index];
        index = (index+1)%n;
       }
    return true;
    }