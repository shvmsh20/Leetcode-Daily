int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int res = 1, mn, mx;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                auto p = q.front();
                q.pop();
                if(i==0){
                    mn = p.second;
                }
                if(i==n-1){
                    mx = p.second;
                }
                if(p.first->left){
                    long long index = 2*(p.second-mn)+1;
                    q.push({p.first->left, index});
                }
                if(p.first->right){
                    long long index = 2*(p.second-mn)+2;
                    q.push({p.first->right, index});
                }
            }
            res = max(res, mx-mn+1);
        }
        return res;
    }