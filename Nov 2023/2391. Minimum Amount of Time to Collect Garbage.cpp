int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        unordered_map<int, unordered_map<char, int>> mp;
        int index=0;
        for(auto x: garbage){
            for(int i=0; i<x.size(); i++){
                mp[index][x[i]]++;
            }
            
            index++;
        }
        int pap=0, gar=0, met=0, pt=0, gt=0, mt=0;
        for(int i=0; i<n; i++){
            auto x = mp[i];
            if(x.find('P')!=x.end()){
                pap+=pt;
                pap+=x['P'];
                pt=0;
            }
            if(i!=n-1) pt+=travel[i];
            if(x.find('G')!=x.end()){
                gar+=gt;
                gar+=x['G'];
                gt=0;
            }
            if(i!=n-1) gt+=travel[i];
            if(x.find('M')!=x.end()){
                met+=mt;
                met+=x['M'];
                mt=0;
            }
            if(i!=n-1) mt+=travel[i];
            
        }
        return pap+gar+met;
    }