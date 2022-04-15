TreeNode* solve(TreeNode* root, int low, int high){
        if(root==nullptr){
            return nullptr;
        }
        if(root->val<low){
            return solve(root->right, low, high);
        }else if(root->val>high){
            return solve(root->left, low, high);
        }else if(root->val>=low && root->val<=high){
            root->left = solve(root->left, low, high);
            root->right = solve(root->right, low, high);
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }