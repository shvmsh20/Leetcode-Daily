void solve(TreeNode* root, vector<int> &res){
        if(root==nullptr){
            return;
        }
        solve(root->left, res);
        res.push_back(root->val);
        solve(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root, res);
        return res;
    }