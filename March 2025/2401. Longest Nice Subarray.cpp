int longestNiceSubarray(vector<int>& nums) {
        int x = 0;
        int j=0;
        int res = 1;
        for(int i=0; i<nums.size(); i++){
            while((x&nums[i])!=0){
                x = x^nums[j];
                j++;
            }
            x = x|nums[i];
            res = max(res, i-j+1);
            
        }
        return res;
    }