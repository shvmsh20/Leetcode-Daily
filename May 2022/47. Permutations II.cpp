void rec(vector<int>& nums, int index, set<vector<int>> &s){
        if(index==nums.size()){
            s.insert(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            rec(nums, index+1, s);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> res;
        int i=0;
        rec(nums, i, s);
        for(auto it = s.begin(); it!=s.end(); it++){
            res.push_back(*it);
        }
        return res;
    }