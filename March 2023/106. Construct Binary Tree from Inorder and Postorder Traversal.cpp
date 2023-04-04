TreeNode* util(int inS, int inE, vector<int> &inorder, int postS, int postE, 
                  vector<int> &postorder, unordered_map<int, int> &mp){
        if(inS>inE || postS>postE){
            return nullptr;
        }
        TreeNode* t = new TreeNode(postorder[postE]);
        int index = mp[postorder[postE]];
        int left = index-inS;
        t->left = util(inS, index-1, inorder, postS, postS+left-1, postorder, mp);
        t->right = util(index+1, inE, inorder, postS+left, postE-1, postorder, mp);
        return t;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return util(0, n-1, inorder, 0, n-1, postorder, mp);
    }