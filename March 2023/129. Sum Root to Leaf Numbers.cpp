void solve(TreeNode* root, int ans, int &res){
        if(root==nullptr){
            return;
        }
        ans+= root->val;
        if(root->left==nullptr && root->right==nullptr){
            res+=ans;
            return;
        }
        solve(root->left, ans*10, res);
        solve(root->right, ans*10, res);
    }
    int sumNumbers(TreeNode* root) {
        int res=0, ans=0;
        solve(root, ans, res);
        return res;
    }