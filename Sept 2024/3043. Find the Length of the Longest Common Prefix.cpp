struct TrieNode{
        TrieNode* child[10];
        TrieNode(){
            for(int i=0; i<=9; i++){
                child[i] = nullptr;
            }
        }
    };
    void insertKey(string &s, TrieNode* root){
        TrieNode* curr = root;
        for(char x: s){
            if(curr->child[x-'0']==nullptr){
                curr->child[x-'0'] = new TrieNode();
            }
            curr = curr->child[x-'0'];
        }
    }
    int solve(TrieNode* root, string &s){
        int res = 0;
        TrieNode* curr = root;
        for(char x: s){
            if(curr->child[x-'0']!=nullptr){
                res++;
                curr = curr->child[x-'0'];
            }else{
                break;
            }
        }
        return res;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();
        for(int x: arr1){
            string s = to_string(x);
            insertKey(s, root);
        }
        int res = 0;
        for(int x: arr2){
            string s = to_string(x);
            res = max(res, solve(root, s));
        }
        return res;
    }