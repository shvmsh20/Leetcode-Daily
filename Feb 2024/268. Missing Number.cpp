int missingNumber(vector<int>& nums) {
       int n = nums.size();
       int res = 0;
       for(int i=0; i<nums.size(); i++){
           res = res ^ nums[i];
           res = res ^ i;
       } 
       res = res ^ n;
       return res;
    }