bool solve(TreeNode* node1, TreeNode* node2){
        if(node1==nullptr && node2==nullptr){
            return true;
        }
        if(node1==nullptr || node2==nullptr){
            return false;
        }
        return node1->val==node2->val && solve(node1->left, node2->right) &&
        solve(node1->right, node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr || (root->left==nullptr && root->right==nullptr)){
            return true;
        }
        return solve(root, root);
    }