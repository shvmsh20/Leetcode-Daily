vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> res;
        while(curr){
            if(curr->left==nullptr){
                res.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right==nullptr){
                    res.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                }else{
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return res;
    }