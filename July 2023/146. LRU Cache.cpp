class Node{
        public: 
            int val;
            int key;
            Node* next;
            Node* prev;
            Node(int key, int val){
                this->key = key;
                this->val = val;
                next = nullptr;
                prev = nullptr;
            }
    };
    unordered_map<int, Node*> mp;
    int n;
    Node* head = new Node(0, 0), *tail = new Node(0, 0);
    LRUCache(int capacity) {
        n = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void insert(Node* temp){
        temp->next = head->next;
        head->next->prev = temp;
        temp->prev = head;
        head->next = temp;
    }
    void del(Node* temp){
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    int get(int key) {
        int ans = -1;
        if(mp.find(key)!=mp.end()){
            Node* temp = mp[key];
            ans = temp->val;
            del(temp);
            insert(temp);
        }
        return ans;
    }
    
    void put(int key, int value) {
        Node* temp = new Node(key, value);
        if(mp.find(key)!=mp.end()){
            Node* old = mp[key];
            del(old);
            mp[key] = temp;
            insert(temp);
        }else{
            if(mp.size()<n){
                mp[key] = temp;
                insert(temp);
            }else{
                Node* last = tail->prev;
                mp.erase(last->key);
                del(last);
                mp[key] = temp;
                insert(temp);
            }
        }
    }