bool solve(int idx, vector<int> &sides, int sL, vector<int>& ms){
        if(idx == ms.size()){
            return true;
        }
        for(int i=0; i<4; i++){
            if(sides[i]+ms[idx]<=sL){
                sides[i]+= ms[idx];
                if(solve(idx+1, sides, sL, ms)){
                    return true;
                }
                sides[i]-=ms[idx];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& ms) {
        int sum=0;
        for(int x: ms){
            sum+= x;
        }
        if(sum%4!=0){
            return false;
        }
        sort(ms.begin(), ms.end(), greater<int>());
        vector<int> sides(4, 0);
        int sL = sum/4;
        return solve(0, sides, sL, ms);
    }