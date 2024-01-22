vector<int> findErrorNums(vector<int>& nums) {
        int xr = 0;
        for(int i=0; i<nums.size(); i++){
            xr = nums[i] ^ xr;
            xr = (i+1) ^ xr;
        }
        int lstSetBit = xr & (~(xr-1));
        int x1 = 0, x2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] & lstSetBit){
                x1 = x1 ^ nums[i];
            }else{
                x2 = x2 ^ nums[i];
            }
            if((i+1) & lstSetBit){
                x1 = x1 ^ (i+1);
            }else{
                x2 = x2 ^ (i+1);
            }

        }
        for(int i=0; i<nums.size(); i++){
            if(x1==nums[i]){
                return {x1, x2};
            }
        }
        return {x2, x1};
    }