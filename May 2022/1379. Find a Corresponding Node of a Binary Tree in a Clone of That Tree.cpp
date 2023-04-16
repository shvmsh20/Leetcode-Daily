TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==nullptr){
            return nullptr;
        }
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if(left!=nullptr){
            return left;
        }
        if(original==target){
            return cloned;
        }
        return getTargetCopy(original->right, cloned->right, target);
    }