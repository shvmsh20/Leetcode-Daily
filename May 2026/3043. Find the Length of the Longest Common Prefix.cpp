 int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        int res = 0;
        int n1 = arr1.size(), n2 = arr2.size();
        for(int x: arr1){
            string s = to_string(x);
            string prefix;
            for(int i=0; i<s.size(); i++){
                prefix.push_back(s[i]);
                st.insert(prefix);
            }
        }
        for(int x: arr2){
            string s = to_string(x);
            string prefix;
            for(int i=0; i<s.size(); i++){
                prefix.push_back(s[i]);
                if(st.find(prefix)!=st.end()){
                    res = max(res, i+1);
                }else{
                    break;
                }
            }
        }
        return res;
    }