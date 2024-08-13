void solve(int index, int n, int target, vector<int> &nums, vector<int> &temp, vector<vector<int>> &res){
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int i=index; i<n; i++){
            if(i==index || nums[i]!=nums[i-1]){
                if(nums[i]<=target){
                    temp.push_back(nums[i]);
                    solve(i+1, n, target-nums[i], nums, temp, res);
                    temp.pop_back();
               
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        solve(0, n, target, nums, temp, res);
        return res;
    }