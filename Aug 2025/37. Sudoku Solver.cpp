bool isSafe(int x, int y, char c, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(board[i][y]==c){
                return false;
            }
            if(board[x][i]==c){
                return false;
            }
            if(board[3*(x/3)+(i/3)][3*(y/3)+(i%3)]==c){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        
        bool dash = false;
        int i, j;
        for(i=0; i<9; i++){
            for(j=0; j<9; j++){
                if(board[i][j]=='.'){
                    dash = true;
                    break;
                }
            }
            if(dash){
                break;
            }
        }
        if(i==9 && j==9){
            return true;
        }
        //cout << i << " " << j << endl;
        for(char x='1'; x<='9'; x++){
            if(isSafe(i, j, x, board)){
                board[i][j] = x;
                if(solve(board)){
                    return true;
                }
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }