TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == NULL) return NULL;

        // enumerate
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        // remove the leaf node with the value `target`
        if ((root->left == NULL) && (root->right == NULL) && (root->val == target)) {
            return NULL;
        }
        return root;
    }