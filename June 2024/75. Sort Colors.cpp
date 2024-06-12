void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l=0, mid=0, h=n-1;
        while(mid<=h){
            if(nums[mid]==0){
                swap(nums[mid], nums[l]);
                l++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[h], nums[mid]);
                h--;
            }
        }
    }