//Using BFS
vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==nullptr){
            return res;
        }
        TreeNode* t;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                t = q.front();
                q.pop();
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                } 
            }
            res.push_back(t->val);
        }
        return res;
    }

//Using recursion
void solve(TreeNode* root, int level, vector<int> &res){
        if(root==nullptr){
            return;
        }
        if(res.size()==level){
            res.push_back(root->val);
        }
        
        solve(root->right, level+1, res);
        solve(root->left, level+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        int level=0;
        vector<int> res;
        solve(root, 0, res);
        return res;
    }
