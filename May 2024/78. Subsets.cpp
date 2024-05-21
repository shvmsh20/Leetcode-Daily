void solve(int index, int n, vector<int> &nums, vector<int> &temp, vector<vector<int>> &res){
        if(index==n){
            res.push_back(temp);
            return;
        }
        solve(index+1, n, nums, temp, res);
        temp.push_back(nums[index]);
        solve(index+1, n, nums, temp, res);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        vector<int> tmp;
        solve(0, n, nums, tmp, res);
        
        return res;
    }