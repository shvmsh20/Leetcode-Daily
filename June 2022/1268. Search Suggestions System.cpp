class TrieNode {
      public:
        vector<string> words;
        vector<TrieNode*> childrens;
  
        TrieNode(){
            childrens.resize(26,nullptr);
        }
};
    class Trie {
    private :
     TrieNode* root;
    public :
    Trie(){
        root = new TrieNode();
    }
    
    void add(string& str){
        TrieNode* node = root;
        for(char ch : str){
            if(node->childrens[ch-'a'] == nullptr)
                node->childrens[ch-'a'] = new TrieNode();
            
            if(node->words.size() < 3){
                node->words.push_back(str);
            }
            
            node = node->childrens[ch-'a'];
        }
        if(node->words.size() < 3){
                node->words.push_back(str);
        }
    }
    
    vector<string> search(string& prefix,int end){
        TrieNode* node = root;
        for(int i = 0; i < end; i++){
            char ch = prefix[i];
            node = node->childrens[ch - 'a'];
            if(node == nullptr) return {};
        }
        
        return node->words;
    }
};
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        
        Trie* tri = new Trie();
        
        for(string str : products)
            tri->add(str);
        
        //answer
        vector<vector<string>> ans;
        
        //do binary search 
       for(int i = 1; i <= searchWord.size(); i++){
            ans.push_back(tri->search(searchWord,i));
       }
        
        
        return ans;
    }