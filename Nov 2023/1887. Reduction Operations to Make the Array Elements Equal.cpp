int reductionOperations(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for(int i = nums.size()-1; i > 0; i--)
            if(nums[i] > nums[i-1])
                count += (nums.size() - i);
        return count;
    }