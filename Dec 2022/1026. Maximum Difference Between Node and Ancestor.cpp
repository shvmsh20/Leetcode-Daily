int maxAncestorDiff(TreeNode* r, int mn = 100000, int mx = 0) {
        return r ? max(maxAncestorDiff(r->left, min(mn, r->val), max(mx, r->val)),
        maxAncestorDiff(r->right, min(mn, r->val), max(mx, r->val))) : mx - mn;
    }