void solve(TreeNode* node, unordered_set<int> &s, vector<TreeNode*> &res){
        if(node==nullptr){
            return;
        }
        solve(node->left, s, res);
        solve(node->right, s, res);
        if(node->left){
            if(s.find(node->left->val)!=s.end()){
                node->left = nullptr;
            }
        }
        if(node->right){
            if(s.find(node->right->val)!=s.end()){
                node->right = nullptr;
            }
        }
        if(s.find(node->val)!=s.end()){
            if(node->left){
                res.push_back(node->left);
            }
            if(node->right){
                res.push_back(node->right);
            }
        }
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s;
        for(int x: to_delete){
            s.insert(x);
        }
        vector<TreeNode*> res;
        solve(root, s, res);
        if(s.find(root->val)==s.end()){
            res.push_back(root);
        }
        return res;
    }