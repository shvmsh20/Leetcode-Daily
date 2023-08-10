bool search(vector<int>& nums, int target) {
        int l=0, h = nums.size()-1;
        while(l<=h){
            int m = (l+(h-l)/2);
            if(nums[m]==target){
                return true;
            }
            if(nums[l]==nums[m] && nums[h]==nums[m]){
                l++;
                h--;
            }
        
            else if(nums[m]<=nums[h]){
                if(target<=nums[h] && target>=nums[m]){
                    l = m+1;
                }else{
                    h = m-1;
                }
            }else{
                if(target>=nums[l] && target<=nums[m]){
                    h = m-1;
                }else{
                    l = m+1;
                }
            }
        }
        return false;
    }