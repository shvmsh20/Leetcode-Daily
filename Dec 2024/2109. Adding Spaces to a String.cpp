string addSpaces(string s, vector<int>& spaces) {
        int n = s.length(), m = spaces.size();
        sort(spaces.begin(), spaces.end());
        int index = 0;
        string res;
        for(int i=0; i<n; i++){
            if(index<m){
                if(spaces[index]==i){
                    res.push_back(' ');
                    index++;
                    i--;
                }else{
                    res.push_back(s[i]);
                }
            }else{
                res.push_back(s[i]);
            }
        }
        return res;
    }