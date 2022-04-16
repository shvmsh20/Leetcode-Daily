int solve(TreeNode* root, int above){
        if(root==nullptr){
            return 0;
        }
        int r = solve(root->right, above);
        int prevRoot = root->val;
        root->val = root->val+above+r;
        int l = solve(root->left, root->val);
        return l+r+prevRoot;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==nullptr){
            return nullptr;
        }
        solve(root, 0);
        return root;
    }