bool canJump(vector<int>& nums) {
        int mxIndex = 0, n = nums.size();
        for(int i=0; i<n; i++){
            int jumpTill = i+nums[i];
            mxIndex = max(mxIndex, jumpTill);
            if(i>=mxIndex){
                break;
            }
        }
        return mxIndex>=n-1?true:false;
    }