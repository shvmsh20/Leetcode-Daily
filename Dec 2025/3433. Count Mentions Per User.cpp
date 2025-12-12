 static bool cmp(vector<string> &a, vector<string> &b){
        int t1 = stoi(a[1]), t2 = stoi(b[1]);
        if(t1!=t2){
            return t1<t2;
        }else{
            return a[0] > b[0];
        }
    }
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        int m = events.size();
        sort(events.begin(), events.end(), cmp);
        unordered_map<int, int> mp;
        vector<int> res(n);
        // for(int i=0; i<m; i++){
        //     cout << events[i][0] << " " << events[i][1] << endl;
        // }
        for(int i=0; i<m; i++){
            vector<string> x = events[i];
            string mes = x[0];
            int time = stoi(x[1]);
            string mt = x[2];
            if(mes=="OFFLINE"){
                int id = stoi(mt);
                mp[id] = 60+time;
            }else{
                if(mt=="HERE"){
                    for(int i=0; i<n; i++){
                        if(mp.find(i)!=mp.end()){
                            if(time>=mp[i]){
                                res[i]++;
                                mp.erase(i);
                            }
                        }else{
                            res[i]++;
                        }
                    }
                }else if(mt=="ALL"){
                    for(int i=0; i<n; i++){
                        res[i]++;
                    }
                }else{
                    int sz = mt.size();
                    string temp;
                    for(int i=0; i<sz; i++){
                        if(mt[i]>='0' && mt[i]<='9'){
                            temp+= mt[i];
                        }else{
                            if(temp.size()){
                                int id = stoi(temp);
                                res[id]++;
                            }
                            temp.clear();
                        }
                    }
                    if(temp.size()){
                        int id = stoi(temp);
                        res[id]++;
                    }
                }
            }
        }
        return res;
    }