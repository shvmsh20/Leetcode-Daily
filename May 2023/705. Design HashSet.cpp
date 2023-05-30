int bucket_size;
    vector<vector<int>> buckets;
    MyHashSet() {
        bucket_size = 15000;
        buckets = vector<vector<int>> (bucket_size, vector<int> {});
        }
    
    void add(int key) {
        int mapped_key = key%bucket_size;
        if(find(buckets[mapped_key].begin(), buckets[mapped_key].end(), key)==buckets[mapped_key].end()){
            buckets[mapped_key].push_back(key);
        }
    }
    
    void remove(int key) {
        int mapped_key = key%bucket_size;
        auto it = find(buckets[mapped_key].begin(), buckets[mapped_key].end(), key);
        if(it!=buckets[mapped_key].end()){
            buckets[mapped_key].erase(it);
        }
    
   
    }
    
    bool contains(int key) {
        int mapped_key = key%bucket_size;
        if(find(buckets[mapped_key].begin(), buckets[mapped_key].end(), key)==buckets[mapped_key].end()){
            return false;
        }
        return true;
    }