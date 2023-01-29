struct Node{
        int key; 
        int val; 
        int count;
        Node* next, *prev;
        Node(int key, int val){
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
            count=1;
        }
    };
    struct List{
        Node* head;
        Node* tail;
        int size;
        List(){
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void add(Node *temp){
            temp->next = head->next;
            temp->prev = head;
            head->next->prev = temp;
            head->next = temp;
            size++;
        }
        void remove(Node* temp){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            size--;
        }
    };
    unordered_map<int, Node*> mp;
    unordered_map<int, List*> freqMap;
    int minFreq;
    int capacity;
    int currSize;
        
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq=0;
        currSize=0;
    }
    void updateFreqListMap(Node* t){
        int currFreq = t->count;
        List* list = freqMap[currFreq];
        list->remove(t);
        if(list->size==0 && minFreq==currFreq){
            minFreq++; 
        }
        List* newList = new List();
        if(freqMap.find(currFreq+1)!=freqMap.end()){
            newList = freqMap[currFreq+1];
        }
        t->count = t->count+1;
        newList->add(t);
        freqMap[t->count] = newList;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* t = mp[key];
            int res = t->val;
            updateFreqListMap(t);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity==0){
            return;
        }
        if(mp.find(key)!=mp.end()){
            Node* t = mp[key];
            t->val = value;
            updateFreqListMap(t);
            return;
        }
        if(capacity==currSize){
            List* list = freqMap[minFreq];
            mp.erase(list->tail->prev->key);
            list->remove(list->tail->prev);
            currSize--;
        }
        currSize++;
        minFreq = 1;
        Node* t = new Node(key, value);
        List* list = new List();
        if(freqMap.find(minFreq)!=freqMap.end()){
            list = freqMap[minFreq];
        }
        list->add(t);
        freqMap[minFreq] = list;
        mp[key] = t; 
    }