bool solve(TreeNode* root, long int mn, long int mx){
        if(root==nullptr){
            return true;
        }
        if(!(mn<root->val && root->val<mx)){
            return false;
        }
        return solve(root->left, mn, root->val) && solve(root->right, root->val, mx);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }