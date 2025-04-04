TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        int maxd = maxDepth(root);
        return dfs(root,maxd,0);    
    }
    TreeNode* dfs(TreeNode* root,int maxd,int len)
    {
        if(root == NULL) return NULL;
        if(maxd-1 == len) return root;

        TreeNode* left = dfs(root->left,maxd,len+1);
        TreeNode* right = dfs(root->right,maxd,len+1);

        if(left && right) return root;
        return left?left:right;
    }
    int maxDepth(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }