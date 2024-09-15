int findTheLongestSubstring(string s) {
        int n = s.size();
        int res = 0, a=0, e=0, i=0, o=0, u=0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int j=0; j<n; j++){
            // cout << s[i] << endl;
            switch(s[j]){
                case 'a':
                    a = (a+1)%2;
                    break;
                case 'e':
                    e = (e+1)%2;
                    break;
                case 'i':
                    i = (i+1)%2;
                    break;
                case 'o':
                    o = (o+1)%2;
                    break;
                case 'u':
                    u = (u+1)%2;
                    break; 
                default:
                    break;
            }
            int state = 0;
            if(a) state = state | 1<<0;
            if(e) state = state | 1<<1;
            if(i) state = state | 1<<2;
            if(o) state = state | 1<<3;
            if(u) state = state | 1<<4;
            // cout << state << endl;
            if(mp.find(state)!=mp.end()){
                res = max(res, j-mp[state]);
            }else{
                mp[state] = j;
            }
        }
        return res;
    }