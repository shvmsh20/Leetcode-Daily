bool checkStraightLine(vector<vector<int>>& cord) {
       int x = cord[0][0], y = cord[0][1], x_diff = cord[1][0]-cord[0][0], y_diff = cord[1][1]-cord[0][1];
       for(int i=2; i<cord.size(); i++){
           int nx_diff = cord[i][0]-x, ny_diff = cord[i][1]-y;
           if((y_diff*nx_diff)!=(ny_diff*x_diff)){
               return false;
           }
       }
       return true;
    }