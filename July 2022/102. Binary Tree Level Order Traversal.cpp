vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int> ans;
            for(int i=0; i<sz; i++){
                TreeNode* t = q.front();
                q.pop();
                ans.push_back(t->val);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            res.push_back(ans);
        }
        return res;
    }