struct Node{
    bool flag;
    Node* child[26];
    Node(){
        flag = false;
        for(int i=0; i<26; i++){
            child[i] = nullptr;
        }
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i] - 'a';
            if(curr->child[index]==nullptr){
                curr->child[index] = new Node();
            }
            curr = curr->child[index];
        }
        curr->flag = true;
    }
    
    bool helper(int index, int n, string &s, Node* curr){
        if(index==n-1){
            if(s[index]=='.'){
                for(int i=0; i<26; i++){
                    if(curr->child[i]!=nullptr && curr->child[i]->flag){
                        return true;
                    }
                }
                return false;
            }else{
                int i = s[index]-'a';
                if(curr->child[i]!=nullptr && curr->child[i]->flag){
                    return true;
                }else{
                    return false;
                }
            }
        }
        if(s[index]=='.'){
            for(int i=0; i<26; i++){
                if(curr->child[i]!=nullptr && helper(index+1, n, s, curr->child[i])){
                    return true;
                }
            }
            return false;
        }else{
            int i = s[index]-'a';
            if(curr->child[i]!=nullptr && helper(index+1, n, s, curr->child[i])){
                return true;
            }
            return false;
        }
    }
    
    bool search(string word) {
        int n = word.length();
        return helper(0, n, word, root);
    }
};