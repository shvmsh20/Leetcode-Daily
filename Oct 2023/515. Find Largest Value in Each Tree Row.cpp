vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root==nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int mx = INT_MIN;
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                mx = max(mx, node->val);
            }
            res.push_back(mx);
        }
        return res;
    }