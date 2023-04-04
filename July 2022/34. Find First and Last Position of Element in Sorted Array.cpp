void utilS(int l, int h, vector<int> &nums, int target, int &res){
        if(l>h){
            return;
        }
        int mid = l+(h-l)/2;
        if(nums[mid]>target){
            utilS(l, mid-1, nums, target, res);
        }else if(nums[mid]<target){
            utilS(mid+1, h, nums, target, res);
        }else{
            res = mid;
            utilS(l, mid-1, nums, target, res);
        }
    }
    void utilE(int l, int h, vector<int> &nums, int target, int &res){
        if(l>h){
            return;
        }
        int mid = l+(h-l)/2;
        if(nums[mid]>target){
            utilE(l, mid-1, nums, target, res);
        }else if(nums[mid]<target){
            utilE(mid+1, h, nums, target, res);
        }else{
            res = mid;
            utilE(mid+1, h, nums, target, res);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;
        utilS(0, nums.size()-1, nums, target, start);
        utilE(0, nums.size()-1, nums, target, end);
        vector<int> res(2);
        res[0] = start;
        res[1] = end;
        return res;
    }