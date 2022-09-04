void solve(int level, int line, TreeNode* root, map<int, map<int, multiset<int>>> &mp){
        if(root==nullptr){
            return;
        }
        mp[line][level].insert(root->val);
        solve(level+1, line-1, root->left, mp);
        solve(level+1, line+1, root->right, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, map<int, multiset<int>>> mp;
        solve(0, 0, root, mp);
        for(auto it: mp){
            vector<int> t;
            for(auto y: it.second){
                t.insert(t.end(), y.second.begin(), y.second.end());
            }
            res.push_back(t);
        }
        return res;
    }