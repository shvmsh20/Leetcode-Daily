bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        int n = 9;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='.'){
                    continue;
                }
                string r = to_string(board[i][j]) + " in row " + to_string(i);
                string c = to_string(board[i][j]) + " in col " + to_string(j);
                string box = to_string(board[i][j]) + " in box " + to_string(i/3)+ " " + to_string(j/3);
                if(s.find(r)!=s.end()){
                    return false;
                }else{
                    s.insert(r);
                }
                if(s.find(c)!=s.end()){
                    return false;
                }else{
                    s.insert(c);
                }
                if(s.find(box)!=s.end()){
                    return false;
                }else{
                    s.insert(box);
                }
            }
        }
        return true;
    }