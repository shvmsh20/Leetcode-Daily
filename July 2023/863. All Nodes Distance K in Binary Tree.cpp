void printNodes(TreeNode* node, int k, vector<int> &res){
        if(node==nullptr || k<0){
            return;
        }
        if(k==0){
            res.push_back(node->val);
            return;
        }
        printNodes(node->left, k-1, res);
        printNodes(node->right, k-1, res);
    }
    int helper(TreeNode* root, TreeNode* target, int k, vector<int> &res){
        if(root==nullptr){
            return -1;
        }
        if(root==target){
            printNodes(root, k, res);
            return 0;
        }
        int dl = helper(root->left, target, k, res);
        if(dl!=-1){
            if((dl+1)==k){
                res.push_back(root->val);
                return -1;
            }else{
                printNodes(root->right, k-dl-2, res);
                return dl+1;
            }
        }
        int dr = helper(root->right, target, k, res);
        if(dr!=-1){
            if((dr+1)==k){
                res.push_back(root->val);
                return -1;
            }else{
                printNodes(root->left, k-dr-2, res);
                return dr+1;
            }
        }
        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        helper(root, target, k, res);
        return res;
    }