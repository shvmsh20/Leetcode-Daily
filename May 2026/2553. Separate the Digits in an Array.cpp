vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i=n-1; i>=0; i--){
            int num = nums[i];
            while(num){
                res.push_back(num%10);
                num = num/10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }