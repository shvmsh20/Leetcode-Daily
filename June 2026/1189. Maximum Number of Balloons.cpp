int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        vector<char> balloon = { 'b','a','l','l','o','o','n'};
        for(char x: text){
            mp[x]++;
        }
        int res = 0;
        while(true){
            bool flag = false;
            for(char x: balloon){
                if(mp.find(x)==mp.end() || mp[x]==0){
                    flag = true;
                    break;
                }
                mp[x]--;
            }
            if(flag){
                break;
            }
            res++;
        }
        return res;
    }