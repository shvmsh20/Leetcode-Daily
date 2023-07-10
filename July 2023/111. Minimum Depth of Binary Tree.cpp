int solve(TreeNode* root){
        if(root==nullptr){
            return INT_MAX;
        }
        if(root->left==nullptr && root->right==nullptr){
            return 1;
        }
        int left = INT_MAX;
        int right = INT_MAX;
        if(root->left){
            left = 1+solve(root->left);
        }
        if(root->right){
            right = 1+solve(root->right);
        }
        int ans = min(left, right);
        return ans==INT_MAX?0:ans;

    }
    int minDepth(TreeNode* root) {
        int ans = solve(root);
        return ans==INT_MAX?0:ans; 
    }