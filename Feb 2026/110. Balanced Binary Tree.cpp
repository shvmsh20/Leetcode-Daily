 int solve(TreeNode* node){
        if(node==nullptr) return 0;
        int leftSubTreeHeight = solve(node->left);
        if(leftSubTreeHeight == -1) return -1;
        int rightSubTreeHeight = solve(node->right);
        if(rightSubTreeHeight == -1) return -1;
        if(abs(leftSubTreeHeight-rightSubTreeHeight)>1) return -1;
        return max(leftSubTreeHeight, rightSubTreeHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root)==-1 ? false : true;
    }