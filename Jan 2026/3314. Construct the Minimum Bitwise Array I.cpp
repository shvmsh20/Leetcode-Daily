vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        for(int j=0; j<n; j++){
            int num = nums[j];
            for(int i=1; i<num; i++){
                if((i | (i+1))==num){
                    res[j] = i;
                    break;
                }
            }
            
        }
        return res;
    }