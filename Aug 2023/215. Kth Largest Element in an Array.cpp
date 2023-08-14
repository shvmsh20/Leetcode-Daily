int qs(int lo, int hi, vector<int> &nums, int index){
        int pivot = nums[hi];
        int i = lo;
        for(int j=lo; j<hi; j++){
            if(nums[j]<pivot){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[hi]);
        if(i==index){
            return pivot;
        }else if(i<index){
            return qs(i+1, hi, nums, index);
        }else if(i>index){
            return qs(lo, i-1, nums, index);
        }
        return 0;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return qs(0, n-1, nums, n-k);
    }