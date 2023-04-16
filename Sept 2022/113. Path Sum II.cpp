void solve(int currSum, TreeNode* curr, int targetSum, vector<int> &ans, vector<vector<int>> &res){
        
       
        currSum+=curr->val;
        ans.push_back(curr->val);
        if(curr->left==nullptr && curr->right==nullptr){
            if(currSum==targetSum){
                res.push_back(ans);
            }
            ans.pop_back();
            return;
        }
        if(curr->left) solve(currSum, curr->left, targetSum, ans, res);
        if(curr->right) solve(currSum, curr->right, targetSum, ans, res);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        vector<int> ans;
        solve(0, root, targetSum, ans, res);
        return res;
    }