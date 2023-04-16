int lHeight(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        return 1+lHeight(root->left);
    } 
    int rHeight(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        return 1+rHeight(root->right);
    } 
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int lh = lHeight(root);
        int rh = rHeight(root);
        if(lh==rh){
            return pow(2, lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }