unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        mp[node] = new Node(node->val);
        for(Node* v: node->neighbors){
            if(mp.find(v)==mp.end()){
                mp[v] = cloneGraph(v);
            }
            mp[node]->neighbors.push_back(mp[v]);
        }
        return mp[node];
    }