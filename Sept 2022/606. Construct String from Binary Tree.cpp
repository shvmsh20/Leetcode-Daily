void solve(TreeNode* root, string &res){
        if(root==nullptr){
            res+="()";
            return;
        }
        
    res+= to_string(root->val);
    if(root->left || root->right){
        if(root->left!=nullptr){
            res+= "(";
            solve(root->left, res);
            res+=")"; 
        }else{
            solve(root->left, res);
        }
        
        if(root->right!=nullptr){
            res+= "(";
            solve(root->right, res);
            res+=")";
        }
    }
        
    }
    string tree2str(TreeNode* root) {
        string res;
        solve(root, res);
        return res;
    }