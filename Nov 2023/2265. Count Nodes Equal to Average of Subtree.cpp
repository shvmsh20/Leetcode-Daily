int result = 0;
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return result;
    }

    vector<int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }

        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);

        int sum = left[0] + right[0] + node->val;
        int count = left[1] + right[1] + 1;

        if (sum / count == node->val) {
            result++;
        }

        return {sum, count};
    }