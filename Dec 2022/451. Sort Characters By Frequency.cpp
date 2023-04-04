static bool cmp(pair<char, int> a, pair<char, int> b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char x: s){
            mp[x]++;
        }
        vector<pair<char, int>> v;
        for(int i=0; i<s.length(); i++){
            v.push_back({s[i], mp[s[i]]});
        }
        sort(v.begin(), v.end(), cmp);
        string temp;
        for(int i=0; i<s.length(); i++){
            temp.push_back(v[i].first);
        }
        return temp;
    }