int solve(string &s, int n, char x, char y, char z){
        unordered_map<int, int> mp;
        int prefixSum = 0, res = 0;
        mp[0] = -1;
        for(int i=0; i<n; i++){
            if(s[i]==z){
                mp.clear();
                prefixSum = 0;
            }else if(s[i]==x){
                prefixSum++;
            }else if(s[i]==y){
                prefixSum--;
            }
            if(mp.find(prefixSum)!=mp.end()){
                res = max(res, i-mp[prefixSum]);
            }else{
                mp[prefixSum] = i;
            }
        }
        return res;
    }
    int solve1(string &s, int n){
        unordered_map<string, int> mp;
        int a = 0, b = 0, c = 0, res = 0;
        mp["0#0"] = -1;
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                a++;
            }else if(s[i]=='b'){
                b++;
            }else{
                c++;
            }
            int c_a = c-a;
            int c_b = c-b;
            string key = to_string(c_a) + "#" + to_string(c_b);
            if(mp.find(key)!=mp.end()){
                res = max(res, i-mp[key]);
            }else{
                mp[key] = i;
            }
        }
        return res;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int res = 1, curr = 1;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                curr++;
            }else{
                curr = 1;
            }
            res = max(res, curr);
        }
        res = max(res, solve(s, n, 'a', 'b', 'c'));
        res = max(res, solve(s, n, 'a', 'c', 'b'));
        res = max(res, solve(s, n, 'b', 'c', 'a'));
        res = max(res, solve1(s, n));
        return res;
    }