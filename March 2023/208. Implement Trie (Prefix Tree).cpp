struct Node{
        bool endswith;
        Node* child[26];
        Node(){
            endswith = false;
            for(int i=0; i<26; i++){
                child[i] = nullptr;
            }
        }
    };
    Node* root = new Node();
    Trie() {
        Node* root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i]-'a';
            if(curr->child[index]==nullptr){
                curr->child[index] = new Node();
            }
            curr = curr->child[index];
        }
        curr->endswith = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i]-'a';
            if(curr->child[index]==nullptr){
                return false;
            }
            curr = curr->child[index];
        }
        return curr->endswith;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0; i<prefix.length(); i++){
            int index = prefix[i]-'a';
            if(curr->child[index]==nullptr){
                return false;
            }
            curr = curr->child[index];
        }
        return true;
    }