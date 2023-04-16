bool solve(TreeNode* curr, int target){
        if(curr==nullptr){
            return false;
        }
        if(curr->left==nullptr && curr->right==nullptr){
            if(curr->val==target){
                return true;
            }else{
                return false;
            }
        }
        
       
        return solve(curr->left, target-curr->val) || solve(curr->right, target-curr->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }