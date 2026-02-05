vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                int index = (i+nums[i])%n;
                // cout << index << endl;
                res[i] = nums[index];
            } else if(nums[i]<0){
                int index = (i-(abs(nums[i])%n)+n)%n;
                // cout << index << endl;
                res[i] = nums[index];
            } else{
                res[i] = 0;
            }
        }
        return res;
    }