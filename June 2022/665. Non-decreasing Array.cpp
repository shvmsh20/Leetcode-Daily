bool checkPossibility(vector<int>& nums) {
        bool check = false;
        int n = nums.size();
        
        for(int i=0;i<n-1;i++)
        {
            if(nums[i] <= nums[i+1])
                continue;
            if(check == true)
                return false;
            
            if(i==0 || nums[i+1] >= nums[i-1])
                nums[i] = nums[i+1];
            else
                nums[i+1] = nums[i];
            
            check = true;
        }
        return true;
    }