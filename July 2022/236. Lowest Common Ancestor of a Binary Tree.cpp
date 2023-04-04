TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q){
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l!=nullptr && r!=nullptr){
            return root;
        }else if(l!=nullptr){
            return l;
        }else if(r!=nullptr){
            return r;
        }else{
            return nullptr;
        }
    }