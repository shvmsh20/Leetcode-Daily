void rev(queue<TreeNode*> &q){
        stack<TreeNode*> st;
        vector<int> res;
        while(!q.empty()){
            st.push(q.front());
            res.push_back(q.front()->val);
            q.pop();
        }
        int index=0;
        while(!st.empty()){
            st.top()->val = res[index++];
            q.push(st.top());
            st.pop();
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* t = q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
            level++;
            if(level%2!=0){
                rev(q);
            }
        }
        return root;
    }