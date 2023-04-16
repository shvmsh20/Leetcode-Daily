TreeNode* solve(int ps, int pe, vector<int>& preorder, int is, int ie, vector<int>& inorder, unordered_map<int, int> &mp){
        if(ps>pe || is>ie){
            return nullptr;
        }
        TreeNode* t = new TreeNode(preorder[ps]);
        int index = mp[preorder[ps]];
        int left = index-is;
        t->left = solve(ps+1, ps+left, preorder, is, index-1, inorder, mp);
        t->right = solve(ps+left+1, pe, preorder, index+1, ie, inorder, mp);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return solve(0, n-1, preorder, 0, n-1, inorder, mp);
    }