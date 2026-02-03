bool isTrionic(vector<int>& nums) {
        int n = nums.size(), p=0;
        while(p+1<n && nums[p+1]>nums[p]){
            p++;
        }
        if(p==0 || p==n-1) return false;
        int q = p;
        while(q+1<n && nums[q+1]<nums[q]){
            q++;
        }
        if(p==q || q==n-1) return false;
        while(q+1<n && nums[q+1]>nums[q]){
            q++;
        }
        return q==n-1;
        
    }