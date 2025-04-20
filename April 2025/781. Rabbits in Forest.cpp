int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int>mp;
        for(int x: answers){
            mp[x]++;
            if(x+1==mp[x]){
                res+= (x+1);
                mp.erase(x);
            }
        }
        for(pair<int, int> x: mp){
            res+= x.first+1;
        }
        return res;
    }