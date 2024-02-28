void solve(TreeNode* node, int &res, int level, int &mxLevel){
        if(node==nullptr){
            return;
        }
        solve(node->left, res, level+1, mxLevel);
        if(level>mxLevel){
            res = node->val;
            mxLevel = level;
        }
        solve(node->right, res, level+1, mxLevel);

    }
    int findBottomLeftValue(TreeNode* root) {
        int res;
        int mxLevel = -1;
        solve(root, res, 0, mxLevel);
        return res;
    }