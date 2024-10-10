int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(nums[i]>rightMax[i+1]){
                rightMax[i] = nums[i];
            }else{
                rightMax[i] = rightMax[i+1];
            }
        }
        int res = 0;
        int left = 0;
        for(int right=1; right<n; right++){
            while(right<n && rightMax[right]>=nums[left]){
                res = max(res, right-left);
                right++;
            }
            left++;
        }
        return res;
    }