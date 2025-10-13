bool isAnagram(string x, string y){
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        return x==y;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);
        for(int i=1; i<words.size(); i++){
            if(isAnagram(res.back(), words[i])){
                continue;
            }else{
                res.push_back(words[i]);
            }
        }
        return res;
    }