int solve(TreeNode* curr, int sum){
        if(curr==nullptr){
            return sum;
        }
        int r = solve(curr->right, sum);
        curr->val = curr->val+r;
        return solve(curr->left, curr->val);
    }
    TreeNode* bstToGst(TreeNode* root) {
        solve(root, 0);
        return root;
    }