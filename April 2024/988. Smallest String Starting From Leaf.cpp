string res="-1";
   
    void solve(TreeNode *root, string &temp){
        if(root==nullptr){
            return;
        }
        temp.push_back('a'+(root->val));
        if(root->left==nullptr && root->right==nullptr){
            string cpy = temp;
            reverse(cpy.begin(), cpy.end());
            if(res=="-1"){
                res = cpy;
                temp.pop_back();
                return;
            }else{  
                res = min(res, cpy);
            }
        }
        solve(root->left, temp);
        solve(root->right, temp);
        temp.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string temp;
        solve(root, temp);
        return res;
    }