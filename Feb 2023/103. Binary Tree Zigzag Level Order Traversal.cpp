vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        stack<TreeNode*> s1, s2;
        s1.push(root);
        bool reverse = true;
        
        while(!s1.empty() || !s2.empty()){
            vector<int> ans;
            if(reverse){
                while(!s1.empty()){
                    TreeNode* t = s1.top();
                    s1.pop();
                    ans.push_back(t->val);
                    if(t->left){
                        s2.push(t->left);
                    }
                    if(t->right){
                        s2.push(t->right);
                    }
                }
            }else{
                while(!s2.empty()){
                    TreeNode* t = s2.top();
                    s2.pop();
                    ans.push_back(t->val);
                    if(t->right){
                        s1.push(t->right);
                    }
                    if(t->left){
                        s1.push(t->left);
                    }
                }
            }
            reverse = !reverse;
            res.push_back(ans);
        }
        return res;
    }