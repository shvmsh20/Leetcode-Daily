TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<TreeNode*> canBeRoot;
        unordered_set<TreeNode*> canNotBeRoot;
        for(vector<int> x: desc){
            int parent = x[0], child = x[1], isLeft = x[2];
            TreeNode* father = nullptr, *son = nullptr;
            if(mp.find(parent)!=mp.end()){
                father = mp[parent];
            }else{
                father = new TreeNode(parent);
                mp[parent] = father;
            }
            if(mp.find(child)!=mp.end()){
                son = mp[child];
            }else{
                son = new TreeNode(child);
                mp[child] = son;
            }
            canBeRoot.insert(father);
            canNotBeRoot.insert(son);
            if(isLeft){
                father->left = son;
            }else{
                father->right = son;
            }
        }
        for(auto it=canBeRoot.begin(); it!=canBeRoot.end(); it++){
            if(canNotBeRoot.find(*it)==canNotBeRoot.end()){
                return *it;
            }
        }
        return nullptr;
    }