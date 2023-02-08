int jump(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=0, res=0;
        while(r<n-1){
            res++;
            int mxIndex = 0;
            for(int i=l; i<=r; i++){
                mxIndex =  max(mxIndex, i+nums[i]);
            }
            if(mxIndex>=n-1){
                return res;
            }
            l = r+1;
            r = mxIndex;
        }
        return 0;
    }