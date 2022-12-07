int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr) return 0;
  return (root->val >= L && root->val <= R ? root->val : 0) +
    rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }