 vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> bitSetIndex(32, INT_MIN);
        int n = nums.size();
        vector<int> res(n);
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<32; j++){
                if(nums[i]&1<<j){
                    bitSetIndex[j] = i;
                }
            }
            int mxlastIndex = i;
            for(int i=0; i<32; i++){
                mxlastIndex = max(bitSetIndex[i], mxlastIndex);
            }
            res[i] = mxlastIndex-i+1;
        }
       return res;
    }