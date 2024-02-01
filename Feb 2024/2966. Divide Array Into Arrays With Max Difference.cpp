vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size(), i = 0;
        while(i<n){
            vector<int> temp(3);
            for(int j=0; j<3; j++){
                temp[j] = nums[i+j];
            }
            if((temp[2]-temp[0])>k){
                return {};
            }
            res.push_back(temp);
            i+=3;
        }
        return res;
    }