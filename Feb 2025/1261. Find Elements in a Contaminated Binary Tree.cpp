unordered_set<int> elements;
    FindElements(TreeNode* root) {
        if(root != nullptr){
            queue<pair<int, TreeNode*>> q;
            q.push({0, root});
            elements.insert(0);
            while(!q.empty()){
                auto [x, node] = q.front();
                q.pop();
                if(node->left != nullptr){
                    q.push({2*x + 1, node->left});
                    elements.insert(2*x + 1);
                }
                if(node -> right != nullptr){
                    q.push({2*x + 2, node -> right});
                    elements.insert(2*x + 2);
                }
            }
        }
    }
    
    bool find(int target) {
        return elements.find(target) != elements.end();
    }