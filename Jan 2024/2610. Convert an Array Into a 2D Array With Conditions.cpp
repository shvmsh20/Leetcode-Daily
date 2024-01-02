vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> res;
        bool flag = true;
        while(flag){
            flag = false;
            vector<int> temp;
            for(auto &x: mp){
                if(x.second){
                    flag = true;
                    temp.push_back(x.first);
                    x.second--;
                }
            }
            if(flag==false){
                break;
            }
            res.push_back(temp);
        }
        return res;
    }