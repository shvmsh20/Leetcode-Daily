string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char x: s){
            mp[x]++;
        }
        vector<pair<int, char>> freq;
        for(auto x: mp){
            freq.push_back({x.second, x.first});
        }
        sort(freq.begin(), freq.end());
        string res;
        for(int i=freq.size()-1; i>=0; i--){
            int cnt = freq[i].first;
            char x = freq[i].second;
            string temp;
            for(int j=0; j<cnt; j++){
                temp+= x;
            }
            res+=temp;
        }
        return res;
    }