class BSTIterator{
        public:
        stack<TreeNode*> st;
        bool stl;
        BSTIterator(TreeNode* root, bool stl){
            this->stl = stl;
            if(stl){
                pushAllLeft(root);
            }else{
                pushAllRight(root);
            }
        }
        void pushAllLeft(TreeNode* root){
            while(root){
                st.push(root);
                root = root->left;
            }
        }
        void pushAllRight(TreeNode* root){
            while(root){
                st.push(root);
                root = root->right;
            }
        }
        
        int next(){
            TreeNode* t = st.top();
            st.pop();
            if(stl){
                pushAllLeft(t->right);
            }else{
                pushAllRight(t->left);
            }
            return t->val;
        }
    };
    bool findTarget(TreeNode* root, int k) {
        
        BSTIterator *it1 = new BSTIterator(root, true);
        BSTIterator *it2 = new BSTIterator(root, false);
        int i = it1->next();
        int j = it2->next();
        while(i<j){
            if(i+j==k){
                return true;
            }else if(i+j<k){
                i = it1->next();
            }else{
                j = it2->next();
            }
        }
        return false;
    }