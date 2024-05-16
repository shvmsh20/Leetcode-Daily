bool evaluateTree(TreeNode* root) {
        if(!root->left && !root->right){
            return root->val ? true: false;
        }
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        if(root->val==2){
            return left || right;
        }else{
            return left && right;
        }
    }