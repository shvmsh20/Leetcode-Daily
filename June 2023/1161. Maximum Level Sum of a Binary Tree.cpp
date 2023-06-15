int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int resLevel = 1, level = 1, mxSum = INT_MIN;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                sum+= node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(mxSum<sum){
                resLevel = level;
                mxSum = sum;
            }
            level++;
        }
        return resLevel;
    }