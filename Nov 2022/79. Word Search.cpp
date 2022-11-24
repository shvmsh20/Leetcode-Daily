int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool dfs(int x, int y, int n, int m, int index, string &word, vector<vector<bool>> &vis, vector<vector<char>>& board){
        if(index==word.size()-1){
            return true;
        }
        vis[x][y] = true;
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==false && word[index+1]==board[nx][ny]){
                if(dfs(nx, ny, n, m, index+1, word, vis, board)){
                    return true;
                }
            }
                
        }
        vis[x][y] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    if(dfs(i, j, n, m, 0, word, vis, board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }