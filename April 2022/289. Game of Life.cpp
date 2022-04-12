void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
       
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int count=0;
                //up
                if(i-1>=0 && (board[i-1][j]==1 || board[i-1][j]==2)){
                    count++;
                }
                //up-right
                if(i-1>=0 && j+1<m && (board[i-1][j+1]==1 || board[i-1][j+1]==2)){
                    count++;
                }
                //right
                if(j+1<m && (board[i][j+1]==1 || board[i][j+1]==2)){
                    count++;
                }
                //right-down
                if(j+1<m && i+1<n && (board[i+1][j+1]==1 || board[i+1][j+1]==2)){
                    count++;
                }
                //down
                if(i+1<n && board[i+1][j]==1){
                    count++;
                }
                //down-left
                if(i+1<n && j-1>=0 && (board[i+1][j-1]==1 || board[i+1][j-1]==2)){
                    count++;
                }
                //left
                if(j-1>=0 && (board[i][j-1]==1 || board[i][j-1]==2)){
                    count++;
                }
                //left-up
                if(i-1>=0 && j-1>=0 && (board[i-1][j-1]==1 || board[i-1][j-1]==2)){
                    count++;
                }
                if(board[i][j]==1){
                   if(count==2 || count==3){
                       board[i][j]=1;
                   }else{
                       board[i][j]=2;
                   }
                    
                    
                }else{
                    if(count==3){
                       board[i][j]=-1;
                   }else{
                       board[i][j]=0;
                   }
                }
            }
            
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==2){
                    board[i][j]=0;
                }else if(board[i][j]==-1){
                    board[i][j]=1;
                }
            }
        }
    }