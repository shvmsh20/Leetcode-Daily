int partitionArray(vector<int>& nums, int k) {
        int count=1, n=nums.size();
        sort(nums.begin(), nums.end());
        int mn = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]-mn>k){
                count++;
                mn = nums[i];
            }
        }
        return count;
        
        
    }