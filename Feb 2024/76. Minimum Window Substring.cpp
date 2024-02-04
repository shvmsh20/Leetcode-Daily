string minWindow(string s, string t) {
        if(t.size()>s.size())
            return "";
        unordered_map<char, int> des;
        for(int i=0; i<t.size(); i++){
            des[t[i]]++;
        }
        unordered_map<char, int> curr;
        unordered_set<char> dis;
        
        int i=0, j=0, n = s.length();
        int st = 0, end = n;
        for(j=0; j<n; j++){
            if(dis.size()<des.size()){
                if(des.find(s[j])!=des.end()){
                    curr[s[j]]++;
                    if(curr[s[j]]==des[s[j]]){
                        dis.insert(s[j]);
                    }
                }
            }
            
                 while(des.size()==dis.size()){
                     if((j-i+1)<(end-st+1)){
                         st = i;
                         end = j;
                     }
                     //cout << res << endl;
                    if(des.find(s[i])!=des.end()){
                        curr[s[i]]--;
                        if(curr[s[i]]<des[s[i]]){
                            dis.erase(s[i]);
                        }
                    }
                    i++;
                }
                
           
           
        }
         if(st==0 && end==n){
                return "";
            }
            return s.substr(st, end-st+1);
        
    }