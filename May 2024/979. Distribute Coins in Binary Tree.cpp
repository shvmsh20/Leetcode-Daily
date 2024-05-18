int traverse (TreeNode* root, int& ans) {
        if(root==NULL) return 0;
        int coins = root->val + traverse (root->left, ans) + traverse (root->right, ans);
        coins--;
        ans += abs(coins);
        return coins;
    }
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        traverse (root, ans);
        return ans;
    }