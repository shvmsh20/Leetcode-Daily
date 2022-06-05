void solve(int col, int n, vector<string> &board, int &count, vector<int> &leftRow,
             vector<int> &upperDiag,  vector<int> &lowerDiag){
        if(col==n){
            count++;
            return;
        }
        for(int row=0; row<n; row++){
            if(leftRow[row]==0 && upperDiag[n-1+col-row]==0 && lowerDiag[row+col]==0){
                leftRow[row]=1;
                upperDiag[n-1+col-row]=1;
                lowerDiag[row+col]=1;
                board[row][col]='Q';
                solve(col+1, n, board, count, leftRow, upperDiag, lowerDiag);
                board[row][col]='.';
                leftRow[row]=0;
                upperDiag[n-1+col-row]=0;
                lowerDiag[row+col]=0;
            }
        }
    }
    int totalNQueens(int n) {
        string s(n, '.');
        vector<string> board(n);
        int count=0;
        vector<int> leftRow(n, 0);
        vector<int> upperDiag(2*n-1, 0);
        vector<int> lowerDiag(2*n-1, 0);
        solve(0, n, board, count, leftRow, upperDiag, lowerDiag);
        return count;
    }