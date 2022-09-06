TreeNode* solve(TreeNode* curr){
        if(curr==nullptr){
            return nullptr;
        }
        TreeNode* l = solve(curr->left);
        TreeNode* r = solve(curr->right);
        if(curr->val==1){
            curr->left = l;
            curr->right = r;
            return curr;
        }else{
            if(l!=nullptr || r!=nullptr){
                curr->left = l;
                curr->right = r;
                return curr;
            }else{
                return nullptr;
            }
        }
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        return solve(root);
    }