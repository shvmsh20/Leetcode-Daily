int maxFreqSum(string s) {
        unordered_map<char, int> v, c;
        for(int x: s){
            if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
                v[x]++;
            }else{
                c[x]++;
            }
        }
        int mx1 = 0, mx2 = 0;
        for(auto it: v){
            mx1 = max(mx1, it.second);
        }
        for(auto it: c){
            mx2 = max(mx2, it.second);
        }
        return mx1+mx2;
    }