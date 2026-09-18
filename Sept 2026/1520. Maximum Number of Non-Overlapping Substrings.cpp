 vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        
        vector<int> fst(26, INT_MAX);
        vector<int> lst(26, INT_MIN);
        for (int i = 0; i < n; i++) {
            fst[s[i] - 'a'] = min(fst[s[i] - 'a'], i);
            lst[s[i] - 'a'] = max(lst[s[i] - 'a'], i);
        }
        
        vector<pair<int, int>> t;
        for (int i = 0; i < 26; i++) {
            if (fst[i] < n) {
                int b = fst[i];
                int e = lst[i];
                for (int j = b; j <= e; j++) {
                    b = min(b, fst[s[j] - 'a']);
                    e = max(e, lst[s[j] - 'a']);
                }
                if (b == fst[i]) {
                    t.emplace_back(e, b);
                }
            }
        }
        
        sort(t.begin(), t.end());
        vector<string> ans;
        int prev = -1;
        for (auto &[e, b] : t) {
            if (b > prev) {
                ans.push_back(s.substr(b, e - b + 1));
                prev = e;
            }
        }
        
        return ans;
    }