vector<int> findRowCol(int num, int n){
        num--;
        int row = num/n;
        int col = num%n;
        if(row&1){
            col = n-1-col;
        }
        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        reverse(board.begin(), board.end());
        int n = board.size();
        queue<pair<int, int>> q;
        unordered_set<int> vis;
        q.push({1, 0});
       
        while(!q.empty()){
            
                pair<int, int> p = q.front();
                int moves = p.second;
                q.pop();
                int number = p.first;
                
                for(int i=1; i<=6; i++){
                    int newNumber = i+number;
                    vector<int>x = findRowCol(newNumber, n);
                    int r = x[0], c = x[1];
                    if(r<n && c<n && vis.find(newNumber)==vis.end()){
                        vis.insert(newNumber);
                        if(board[r][c]!=-1){
                            newNumber = board[r][c];
                        }
                        if(newNumber==n*n){
                            return moves+1;
                        }
                        q.push({newNumber, moves+1});
                    }
                }
                
                
            
        }
        return -1;
    }