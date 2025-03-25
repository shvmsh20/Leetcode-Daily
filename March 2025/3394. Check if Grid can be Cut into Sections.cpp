bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> yDir, xDir;
        for(vector<int> rect: rectangles){
            yDir.push_back({rect[1], rect[3]});
            xDir.push_back({rect[0], rect[2]});
        }
        sort(xDir.begin(), xDir.end());
        sort(yDir.begin(), yDir.end());
        vector<int> curr = xDir[0];
        int cnt = 1;
        for(int i=1; i<xDir.size(); i++){
            if(xDir[i][0]>=curr[1]){
                curr = xDir[i];
                cnt++;
            }else{
                curr[1] = max(curr[1], xDir[i][1]);
            }
            if(cnt==3){
                // cout << "jsdfu";
                return true;
            }
        }
        cnt = 1;
        curr = yDir[0];
        for(int i=1; i<yDir.size(); i++){
            if(yDir[i][0]>=curr[1]){
                curr = yDir[i];
                cnt++;
            }else{
                curr[1] = max(curr[1], yDir[i][1]);
            }
            if(cnt==3){
                return true;
            }
        }
        return false;
    }