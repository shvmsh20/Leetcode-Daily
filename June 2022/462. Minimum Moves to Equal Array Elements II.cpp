int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans=0;
        int l=0, r=n-1;
        while(l<r){
            ans+= (nums[r]-nums[l]);
            l++;
            r--;
        }
        return ans;
        
    }