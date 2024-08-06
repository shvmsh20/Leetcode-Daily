static bool cmp(pair<char, int> &p1, pair<char, int> &p2){
        return p1.second>p2.second;
    }
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for(char x: word){
            mp[x]++;
        }
        vector<pair<char, int>> res(mp.begin(), mp.end());
        sort(res.begin(), res.end(), cmp);
        int ans = 0, distChar = 0;
        for(pair<char, int> p: res){
            int freq = p.second, temp;
            distChar++;
            if(distChar<=8){
                temp = 1;
            }else if(distChar<=16){
                temp=2;
            }
            else if(distChar<=24){
                temp=3;
            }else{
                temp = 4;
            }
            ans+=   (temp)*freq;
        }
        return ans;
    }