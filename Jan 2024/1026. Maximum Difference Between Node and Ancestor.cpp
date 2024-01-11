pair<int, int> solve(TreeNode* node, int &res){
        if(node==nullptr){
            return {-1, -1};
        }
        pair<int, int> left = solve(node->left, res);
        pair<int, int> right = solve(node->right, res);
        int leftRes = left.first == -1 ? 0 : abs(node->val-left.first);
        leftRes = max(leftRes, left.second == -1 ? 0 : abs(node->val-left.second));
        int rightRes = right.first == -1 ? 0 : abs(node->val-right.first);
        rightRes = max(rightRes, right.second == -1 ? 0 : abs(node->val-right.second));
        res = max(res, max(leftRes, rightRes));
        int mn = node->val, mx = node->val;
        if(left.first!=-1){
            mn = min(mn, left.first);
        }
        if(right.first!=-1){
            mn = min(mn, right.first);
        }
        
        if(left.second!=-1){
            mx = max(mx, left.second);
        }
        if(right.second!=-1){
            mx = max(mx, right.second);
        }
        return {mn, mx};
    }
    int maxAncestorDiff(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }