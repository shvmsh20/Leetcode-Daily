int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        for(int x: nums){
            mx = max(mx, x);
        }
        int res = 1;
        for(int i=0; i<n; i++){
            if(nums[i]==mx){
                int ans = 0;
                while(i<n && nums[i]==mx){
                    ans++;
                    i++;
                }
                res = max(res, ans);
            }
        }
        return res;
    }