int areaOfMaxDiagonal(vector<vector<int>>& arr) {
        int n = arr.size();
        int mxArea = 0;
        double mxDiag = 0.0;
        for(auto x: arr){
            int len = x[0], width = x[1];
            double diag = sqrt(pow(len, 2)+pow(width, 2));
            if(diag>mxDiag){
                mxArea =len*width;
                mxDiag = diag;
            }else if(diag==mxDiag){
                mxArea = max(mxArea, len*width);
            }
        }
        return mxArea;
    }