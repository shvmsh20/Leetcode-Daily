int res = INT_MIN;
    int solve(TreeNode* curr){
        if(curr==nullptr){
            return 0;
        }
        int l = solve(curr->left);
        int r = solve(curr->right);
        res = max(max(res, curr->val), max(l+curr->val, r+curr->val));
        res = max(res, l+r+curr->val);
        return max(max(l, r)+curr->val, curr->val);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return res;
    }