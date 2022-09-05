vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> t;
            while(n--){
                Node* node = q.front();
                q.pop();
                t.push_back(node->val);
                for(Node* child: node->children){
                    if(child!=nullptr){
                        q.push(child);
                    }
                }
            }
            res.push_back(t);
        }
        return res;
    }