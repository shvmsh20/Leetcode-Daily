vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, int> mp;
        vector<vector<string>> res;
        vector<string> temp;
        int counter=0;
        for(string s: paths){
            string path;
            int n = s.length(), i=0;
            while(i<n && !(s[i]==' ')){
                path+= s[i];
                i++;
            }
            i++;
            path+='/';
            while(i<n){
                string file;
                while(s[i]!='('){
                    file+=s[i];
                    i++;
                }
                i++;
                string content;
                while(s[i]!=')'){
                    content+=s[i];
                    i++;
                }
                string complete = path+file;
                i+=2;
                if(mp.find(content)!=mp.end()){
                    int index = mp[content];
                    res[index].push_back(complete);
                }else{
                    res.push_back(temp);
                    res[res.size()-1].push_back(complete);
                    mp[content] = counter;
                    counter++;
                }
            }
            
            
        }
        vector<vector<string>> ans;
            for(int i=0; i<res.size(); i++){
                if(res[i].size()==1){
                    continue;
                }
                ans.push_back(res[i]);
            }
        return ans;
    }