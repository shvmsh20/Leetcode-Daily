int c=0;
    int solve(TreeNode* root)
    {
        if(root==NULL) return 1;
        int l=solve(root->left);
        int r=solve(root->right);
        
        if(l==0 || r==0)
        {
            c++;
            return 2;
        }
        if(l==2 || r==2)
        {
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(solve(root)==0)
            c++;
        return c; 
    }