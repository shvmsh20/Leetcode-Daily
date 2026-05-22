int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            // check if left is sorted
            if(nums[left]<=nums[mid]){
                if(target>=nums[left] && target<nums[mid]){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{ // right is sorted
                if(target>nums[mid] && target<=nums[right]){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
            // cout << left << " " << right << endl;
        }
        return -1;
    }