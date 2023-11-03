vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int sze = target.size();
        int j=1;
        for(int i=0; i<sze; i++){
            while(j<=n){
                res.push_back("Push");
                if(j==target[i]){
                    j++;
                    break;
                }else{
                    res.push_back("Pop");
                }
                j++;
            }
        }
        return res;
    }