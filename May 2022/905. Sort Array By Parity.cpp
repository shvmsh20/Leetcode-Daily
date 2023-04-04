vector<int> sortArrayByParity(vector<int>& nums) {
        int i=-1;
        int j=0, n = nums.size();
        while(j<n){
            if(nums[j]%2==0){
                i++;
                swap(nums[i], nums[j]);
            }
            j++;
        }
        return nums;
    }