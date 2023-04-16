int v[1000001];
    MyHashSet() {
        memset(v, -1, sizeof(v));
    }
    
    void add(int key) {
        v[key] = 1;
    }
    
    void remove(int key) {
        v[key] = -1;
    }
    
    bool contains(int key) {
        if(v[key]==1){
            return true;
        }
        return false;
    }