int lLevel=0;
    int sum=0;
    void solve(TreeNode* node, int currLevel){
        if(node==nullptr){
            return;
        }
        if(currLevel==lLevel){
            sum+=node->val;
        }
        if(currLevel>lLevel){
            sum = node->val;
            lLevel++;
        }
        solve(node->left, currLevel+1);
        solve(node->right, currLevel+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        solve(root, 1);
        return sum;
    }