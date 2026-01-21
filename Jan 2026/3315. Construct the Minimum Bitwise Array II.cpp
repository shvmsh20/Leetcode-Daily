vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        for(int i=0; i<n; i++){
            int num = nums[i];
            if(num==2){
                continue;
            }
            int pos = 0;
            while(num & (1<<pos)){
                pos++;
            }
            pos--;
            res[i] = num & ~(1<<pos);
        }
        return res;
    }