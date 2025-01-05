string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> shift(n+1);
        for(auto x: shifts){
            if(x[2]==1){
                shift[x[0]]++;
                shift[x[1]+1]--;
            }else{
                shift[x[0]]--;
                shift[x[1]+1]++;
            }
        }
        for(int i=1; i<n; i++){
            shift[i]+= shift[i-1];
        }
        string res;
        for(int i=0; i<n; i++){
            int dist = ((shift[i]%26)+26)%26;
            dist = (dist + (s[i]-'a'))%26;
            char x = 'a'+dist;
            res.push_back(x);

        }
        return res;
    }