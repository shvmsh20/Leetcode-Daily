TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* t = new TreeNode(val);
            t->left = root;
            return t;
        }
        int dpt=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* t = q.front();
                q.pop();
                if(dpt==depth-1){
                    TreeNode* temp1 = t->left;
                    TreeNode* temp2 = t->right;
                    t->left = new TreeNode(val);
                    t->right = new TreeNode(val);
                    t->left->left = temp1;
                    t->right->right = temp2;
                }else{
                    if(t->left){
                        q.push(t->left);
                    }
                    if(t->right){
                        q.push(t->right);
                    }
                }
            }
            dpt++;
            if(dpt==depth){
                break;
            }
        }
        return root;
    }