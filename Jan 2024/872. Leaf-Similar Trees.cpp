void leafNodes(TreeNode* node, vector<int> &res){
        if(node==nullptr){
            return;
        }
        leafNodes(node->left, res);
        if(node->left==nullptr && node->right==nullptr){
            res.push_back(node->val);
        }
        leafNodes(node->right, res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;
        leafNodes(root1, res1);
        leafNodes(root2, res2);
        if(res1.size()!=res2.size()){
            return false;
        }
        for(int i=0; i<res1.size(); i++){
            if(res1[i]!=res2[i]){
                return false;
            }
        }
        return true;
    }