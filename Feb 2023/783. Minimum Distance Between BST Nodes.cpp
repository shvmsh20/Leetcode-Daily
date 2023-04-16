int prev = INT_MAX;
    int res = INT_MAX;
    void inorder(TreeNode* root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        int diff = abs(prev-root->val);
        res = min(diff, res);
        prev = root->val;
        inorder(root->right);

    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return res;
    }