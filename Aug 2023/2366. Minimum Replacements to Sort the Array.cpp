long long minimumReplacement(vector<int>& nums) {
        long long res=0;
        int n = nums.size();
        int last = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(nums[i]<=last){
                last = nums[i];
            }else{
                int parts=ceil(1.00*nums[i]/last);
                last = nums[i]/parts;
                res+= (parts-1);
            }
        }
        return res;
    }