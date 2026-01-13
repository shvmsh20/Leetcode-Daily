double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        double left = 1e9;
        double right = 0;
        for(int i=0; i<n; i++){
            left = min(left, (double)squares[i][1]);
            right = max(right, (double)((squares[i][1]+squares[i][2])));
        }
        while(right-left>=1e-6){
            double mid = double(left+right)/2.00;
            long double above = 0, below = 0;
            for(int i=0; i<n; i++){
                double top = squares[i][1]+squares[i][2], bottom = squares[i][1];
                if(mid>top){
                    below+= (long double)((long double)squares[i][2]*(long double)squares[i][2]);
                }else if(mid<bottom){
                    above+= (long double)((long double)squares[i][2]*(long double)squares[i][2]);
                }else{
                    above+= (((long double)(top)-mid) * (long double)(squares[i][2]));
                    below+=( (mid-(long double)squares[i][1]) * (long double)(squares[i][2]));
                }
                // cout << above << " " << below << endl;
            }
             // cout << above << " " << below <<  " "  << left << " " << right << " " << mid << endl;
            if(above>below){
                    left = mid;
                }else{
                    right = mid;
                }
            // cout << above << " " << below <<  " "  << left << " " << right << endl;
        }
        return left;
    }