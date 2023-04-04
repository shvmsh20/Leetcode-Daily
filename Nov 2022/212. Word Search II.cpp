struct Node{
        int end;
        Node* child[26];
        Node(){
            end=0;
            for(int i=0; i<26; i++){
                child[i] = nullptr;
            }
        }
    };
    void buildTrie(Node* curr, string &x){
        int n = x.length();
        for(int i=0; i<n; i++){
            int index = x[i]-'a';
            if(curr->child[index]==nullptr){
                curr->child[index] = new Node();
            }
            curr = curr->child[index];
        }
        curr->end++;
    }
    void dfs(int i, int j, int n, int m, vector<vector<char>>& board, Node* curr, string &temp, vector<string> &res){
        if(i<0 || i==n || j<0 || j==m || board[i][j]=='$'){
            return;
        }
        int index = board[i][j]-'a';
        if(curr->child[index]==nullptr){
            return;
        }
        char c = board[i][j];
        board[i][j] = '$';
        curr = curr->child[index];
        temp+=c;
        if(curr->end!=0){
            curr->end--;
            res.push_back(temp);
        }
        dfs(i+1, j, n, m, board, curr, temp, res);
        dfs(i, j+1, n, m, board, curr, temp, res);
        dfs(i-1, j, n, m, board, curr, temp, res);
        dfs(i, j-1, n, m, board, curr, temp, res);
        temp.pop_back();
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        for(string x: words){
            buildTrie(root, x);
        }
        int n = board.size();
        int m = board[0].size();
        vector<string> res;
        string temp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dfs(i, j, n, m, board, root, temp, res);
            }
        }
        return res;
    }