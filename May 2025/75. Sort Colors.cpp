void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        for(int i=0; i<=right; i++){
            if(nums[i]==0){
                swap(nums[i], nums[left]);
                left++;
            }else if(nums[i]==1){
                continue;
            }else{
                swap(nums[i], nums[right]);
                right--;
                i--;
            }
        }
    }