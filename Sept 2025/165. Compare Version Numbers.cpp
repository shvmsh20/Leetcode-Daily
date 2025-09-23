string performRevision(string v){
        string res;
        string tmp = "";
        for(int i=0; i<v.size(); i++){
            if(v[i]!='.'){
                if(v[i]=='0'){
                    if(tmp.size()){
                        tmp+= v[i];
                    }
                }else{
                    tmp+= v[i];
                }
            }else{
                if(tmp.size()){
                    res+= '.'+tmp;
                }else{
                    res+= ".0";
                }
                tmp = "";
            }
        }
        if(tmp.size()){
            res+= '.'+tmp;
        }else{
            res+= ".0";
        }
        return res.substr(1);
    }
    int compareVersion(string version1, string version2) {
        string v1 = performRevision(version1);
        string v2 = performRevision(version2);
        int i=0, j=0, n=v1.size(), m=v2.size();
        while(i<n || j<m){
            string t1 = "", t2 = "";
            while(i<n && v1[i]!='.'){
                t1+= v1[i];
                i++;
            }
            i++;
            while(j<m && v2[j]!='.'){
                t2+= v2[j];
                j++;
            }
            j++;
            int x = t1.size() ? stoi(t1): 0;
            int y = t2.size() ? stoi(t2) : 0;
            if(x<y){
                return -1;
            }else if(x>y){
                return 1;
            }

        }
        return 0;
    }