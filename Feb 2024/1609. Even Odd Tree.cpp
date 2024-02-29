bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        int initialValue;
        while(!q.empty()){
            int n = q.size();
            if(level&1){
                initialValue = INT_MAX;
            }else{
                initialValue = INT_MIN;
            }
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                if(level%2==1){
                    if(node->val>=initialValue || node->val%2==1){
                        return false;
                    }
                }else{
                    if(node->val<=initialValue || node->val%2==0){
                        return false;
                    }
                }
                initialValue = node->val;
            }
            level = !level;
        }
        return true;
    }