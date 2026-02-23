bool hasAllCodes(string s, int k) {
        int n=s.size(), i=0;
        if(k>n) return false;
        unordered_set<string> st;
        
        string x;
        while(i<k){
            x.push_back(s[i++]);
        }
        st.insert(x);
        for(; i<n; i++){
            x.erase(0, 1);
            x.push_back(s[i]);
            st.insert(x);
        }
        return st.size()==pow(2, k);
    }