struct TrieNode{
        TrieNode* child[26];
        int freq;
        TrieNode(){
            for(int i=0; i<26; i++){
                child[i] = nullptr;
            }
            freq = 0;
        }
    };
    void buildTrie(TrieNode* root, string &s){
        TrieNode* curr = root;
        for(char x: s){
            if(curr->child[x-'a']==nullptr){
                curr->child[x-'a'] = new TrieNode();
            }
            curr = curr->child[x-'a'];
            curr->freq++;
        }
    }
    int searchTree(TrieNode* root, string &s){
        int res = 0;
        TrieNode* curr = root;
        for(char x: s){
            curr = curr->child[x-'a'];
            res+= curr->freq;
        }
        return res;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        TrieNode* root = new TrieNode();
        vector<int> res;
        for(string x: words){
            buildTrie(root, x);
        }
        for(string word: words){
            res.push_back(searchTree(root, word));
        }
        return res;
    }