int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int pos = n-k;
        int l = 0, r = n-1;
        while(l<=r){
            int pvt = nums[r];
            int x=l;
            for(int i=l; i<r; i++){
                if(nums[i]<=pvt){
                    swap(nums[i], nums[x]);
                    x++;
                }
            }
            swap(nums[x], nums[r]);
            if(x==pos){
                return nums[x];
            }else if(x<pos){
                l = x+1;
            }else{
                r = x-1;
            }
        }
        return 0;
    }