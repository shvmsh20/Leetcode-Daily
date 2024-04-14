int solve(TreeNode* node, int left){
        if(node==nullptr){
            return 0;
        }
        if(node->left==nullptr && node->right==nullptr){
            if(left){
                return node->val;
            }else{
                return 0;
            }
        }

        int res = 0;
        res+= solve(node->left, 1);
        res+= solve(node->right, 0);
        return res;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, 0);
    }