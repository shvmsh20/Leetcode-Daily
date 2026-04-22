int countDiff(string &a, string &b){
        int count=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]!=b[i]){
                count++;
            }
            if(count>2){
                break;
            }
        }
        return count;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        vector<string> res;
        int n = queries[0].size();
        for(string x: queries){
            for(int i=0; i<dict.size(); i++){
                if(countDiff(x, dict[i])<=2){
                    res.push_back(x);
                    break;
                }
            }
        }
        return res;
    }