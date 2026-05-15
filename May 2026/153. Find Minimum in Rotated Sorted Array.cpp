int findMin(vector<int>& nums) {
        // striver's
        int lo = 0, hi = nums.size()-1;
        int res = INT_MAX;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[lo]<=nums[mid]){
                res = min(res, nums[lo]);
                lo = mid+1;
            }else{
                res = min(res, nums[mid]);
                hi = mid-1;
            }
        }
        return res;
    }