TreeNode* search(TreeNode* curr, int val){
        if(curr==nullptr){
            return nullptr;
        }
        if(curr->val==val){
            return curr;
        }
        else if(curr->val>val){
            return search(curr->left, val);
        }
        else if(curr->val<val){
            return search(curr->right, val);
        }
        else{
            return nullptr;
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return search(root, val);
    }