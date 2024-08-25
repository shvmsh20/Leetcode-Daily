void postOrder(TreeNode* node, vector<int> &res){
        if(!node){
            return;
        }
        postOrder(node->left, res);
        postOrder(node->right, res);
        res.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }