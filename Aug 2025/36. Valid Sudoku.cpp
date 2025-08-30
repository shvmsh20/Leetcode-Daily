bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        // check for rows
        for(int i=0; i<n; i++){
            unordered_set<int> s;
            for(int j=0; j<m; j++){
                if(board[i][j]!='.'){
                    if(s.find(board[i][j])!=s.end()){
                        return false;
                    }
                    s.insert(board[i][j]);
                }
            }
        }
        // check for columns
        for(int j=0; j<m; j++){
            unordered_set<int> s;
            for(int i=0; i<n; i++){
                if(board[i][j]!='.'){
                    if(s.find(board[i][j])!=s.end()){
                        return false;
                    }
                    s.insert(board[i][j]);
                }
            }
        }
        // check for 3*3 grids
        for(int i=0; i<n; i+=3){
            for(int j=0; j<m; j+=3){
                unordered_set<int> s;
                for(int x=i; x<i+3; x++){
                    for(int y=j; y<j+3; y++){
                        if(board[x][y]!='.'){
                            if(s.find(board[x][y])!=s.end()){
                                return false;
                            }
                            s.insert(board[x][y]);
                        }
                    }
                }
            }
        }
        return true;

    }