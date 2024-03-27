int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int i=0, j=0, n=nums.size(), product=1, res=0;
        while(j<n){
            product = product*nums[j];
            while(i<=j && product>=k){
                product = product/nums[i];
                i++;
            }
            res+= (j-i+1);
            j++;
        }
        return res;
    }