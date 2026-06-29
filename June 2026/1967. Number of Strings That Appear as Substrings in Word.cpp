int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string> s;
        int n = word.size();
        for(int i=0; i<n; i++){
            string x;
            for(int j=i; j<n; j++){
                x.push_back(word[j]);
                s.insert(x);
            }
        }
        int res = 0;
        for(string x: patterns){
            if(s.find(x)!=s.end()){
                res++;
            }
        }
        return res;
    }