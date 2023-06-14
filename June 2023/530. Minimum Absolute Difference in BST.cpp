int res = INT_MAX;
    int prevVal = INT_MAX;
    void inorder(TreeNode* node){
        if(node==nullptr){
            return;
        }
        inorder(node->left);
        res = min(res, abs(prevVal-node->val));
        prevVal = node->val;
        inorder(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return res;
    }