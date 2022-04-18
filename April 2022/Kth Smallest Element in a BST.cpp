// Recursive
int inorder(TreeNode*curr, int &k){
        if(curr==nullptr){
            return INT_MAX;
        }
        int l = inorder(curr->left, k);
        if(l!=INT_MAX){
            return l;
        }
        if(k==1){
            return curr->val;
        }
        k--;
        int r = inorder(curr->right, k);
        if(r!=INT_MAX){
            return r;
        }
        return INT_MAX;
    }
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }

//Iterative
int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        while(!st.empty() || root){
            while(root){
                st.push(root);
                root=root->left;
            }
            TreeNode *curr = st.top();
            st.pop();
            if(k==1){
                return curr->val;
            }
            k--;
            root = curr->right;
        }
        return 0;
    }