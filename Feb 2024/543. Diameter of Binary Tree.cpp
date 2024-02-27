int solve(TreeNode* node, int &res){
        if(node==nullptr){
            return 0;
        }
        int left = solve(node->left, res);
        int right = solve(node->right, res);
        res = max(res, left+right);
        return max(left, right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        solve(root, res);
        return res;
    }