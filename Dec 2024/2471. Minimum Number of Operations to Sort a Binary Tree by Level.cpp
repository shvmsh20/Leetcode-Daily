int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int res = 0;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> nodes;
            int ans = 0;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                nodes.push_back(node->val);
            }
            vector<int> temp = nodes;
            sort(temp.begin(), temp.end());
            unordered_map<int, int> mp;
            int sz = temp.size();
            for(int i=0; i<sz; i++){
                mp[temp[i]] = i;
            }
            for(int i=0; i<n; i++){
                while(nodes[i]!=temp[i]){
                    res++;
                    swap(nodes[i], nodes[mp[nodes[i]]]);
                }
            }
        }
        return res;
    }