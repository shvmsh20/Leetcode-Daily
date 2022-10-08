int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res, diff = INT_MAX;
        for(int i=0; i<n-2; i++){
            int lo = i+1;
            int hi = n-1;
            while(lo<hi){
                int sum = nums[i]+nums[lo]+nums[hi];
                if(sum==target){
                    return target;
                }
                if(diff>(abs(target-sum))){
                        res = sum;
                        diff = abs(target-sum);
                }
                if(sum<target){
                    lo++;
                }else{
                    hi--;
                }
            }
        }
        return res;
    }