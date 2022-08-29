Node* prev = nullptr;
    Node * bToDLL(Node *root)
    {
        // your code here
        if(root==nullptr){
            return root;
        }
        Node* head = bToDLL(root->left);
        if(prev==nullptr){
            head = root;
            
        }else{
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        bToDLL(root->right);
        return head;
    }