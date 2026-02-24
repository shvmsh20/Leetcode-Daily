int base10Convert(string s){
        reverse(s.begin(), s.end());
        int res = 0;
        for(int i=0; i<s.size(); i++){
            res+= ((s[i]-'0')*pow(2,i));
        }
        return res;
    }
    int solve(TreeNode* node, string s){
        if(node->val){
            s.push_back('1');
        }else{
            s.push_back('0');
        }
        if(node->left==nullptr && node->right==nullptr){
            return base10Convert(s);
        }
        int res = 0;
        if(node->left){
            res+= solve(node->left, s);
        }
        if(node->right){
            res+= solve(node->right, s);
        }
        return res;
    }
    int sumRootToLeaf(TreeNode* root) {
        string s;
        return solve(root, s);
    }