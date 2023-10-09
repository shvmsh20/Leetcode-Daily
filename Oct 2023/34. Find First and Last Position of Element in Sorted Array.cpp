int startingPos(int lo, int hi, vector<int> &nums, int target){
        int res = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==target){
                res = mid;
                hi = mid-1;
            }else if(nums[mid]<target){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return res;
    }
    int lastPos(int lo, int hi,vector<int> &nums, int target){
        int res = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==target){
                res = mid;
                lo = mid+1;
            }else if(nums[mid]<target){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int st = startingPos(0, n-1, nums, target);
        int lst = lastPos(0, n-1, nums, target);
        return {st, lst};
    }