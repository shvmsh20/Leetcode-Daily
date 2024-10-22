long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            long long sum = 0;
            for(int i=0; i<n; i++){
                TreeNode* front = q.front();
                q.pop();
                sum+= front->val;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            res.push_back(sum);
        }
        int sz = res.size();
        if(k>sz){
            return -1;
        }
        sort(res.rbegin(), res.rend());
        return res[k-1];
    }