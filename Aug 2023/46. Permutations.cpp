void solve(int index, int n, vector<int> &nums, vector<vector<int>> &res){
        if(index==n){
            res.push_back(nums);
            return;
        }
        for(int i=index; i<n; i++){
            swap(nums[index], nums[i]);
            solve(index+1, n, nums, res);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        solve(0, n, nums, res);
        return res;
    }