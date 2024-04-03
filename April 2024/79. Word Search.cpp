int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool dfs(int x, int y, int n, int m, int index, int sz, string &word, vector<vector<char>>& board){
        
        if(board[x][y]!=word[index]){
            return false;
        }
        if(index==sz-1){
            return true;
        }
        char cpy = board[x][y];
        board[x][y] = '*';
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny]!='*'){
                if(dfs(nx, ny, n, m, index+1, sz, word, board)){
                    return true;
                }
            }
        }
        board[x][y] = cpy;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size(), sz = word.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    if(dfs(i, j, n, m, 0, sz, word, board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }