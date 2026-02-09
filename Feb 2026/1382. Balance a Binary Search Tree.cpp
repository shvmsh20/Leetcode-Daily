void inorder(TreeNode* node, vector<int> &arr){
        if(node==nullptr){
            return;
        }
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
    }
    TreeNode* solve(int left, int right, vector<int> &arr){
        if(left>right){
            return nullptr;
        }
        int mid = (left+right)/2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = solve(left, mid-1,arr);
        node->right = solve(mid+1, right, arr);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        int n = arr.size();
        return solve(0, n-1, arr);
    }