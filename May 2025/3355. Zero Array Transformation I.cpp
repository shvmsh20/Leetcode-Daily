bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> temp(n+1, 0);
        for(vector<int>x: queries){
            temp[x[0]]--;
            temp[x[1]+1]++;
        }
        int prev = 0;
        for(int i=0; i<n; i++){
            if(nums[i]+temp[i]+prev>0){
                return false;
            }
            prev+= temp[i];
        }
        return true;
    }