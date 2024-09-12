int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s;
        for(char x: allowed){
            s.insert(x);
        }
        int res = 0;
        for(string x: words){
            bool flag = true;
            for(char y: x){
                if(s.find(y)==s.end()){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res++;
            }
        }
        return res;
    }