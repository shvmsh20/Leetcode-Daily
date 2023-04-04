static bool cmp(char a, char b){
        return a<b;
    }
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        sort(s.begin(), s.end(), cmp);
        sort(t.begin(), t.end(), cmp);
        return s==t;
    }