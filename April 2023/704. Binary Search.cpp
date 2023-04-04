int solve(int st, int en, vector<int> &nums, int target){
        if(st>en){
            return -1;
        }
       
        int mid = st+(en-st)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]>target){
            return solve(st, mid-1, nums, target);
        }else{
            return solve(mid+1, en, nums, target);
        }
    }
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        return solve(i, j, nums, target);
    }