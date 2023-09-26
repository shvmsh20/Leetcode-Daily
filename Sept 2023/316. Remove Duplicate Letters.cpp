string removeDuplicateLetters(string s) {
        vector<bool> vis(26, false);
        stack<char> st;
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        st.push(s[0]);
        mp[s[0]]--;
        vis[s[0]-'a'] = true;
        for(int i=1; i<s.length(); i++){
            if(!vis[s[i]-'a']){
                if(st.top()>s[i]){
                    while(!st.empty() && st.top()>s[i] && mp[st.top()]!=0){
                        vis[st.top()-'a'] = false;
                        st.pop();
                    }
                }
                st.push(s[i]);
                vis[s[i]-'a'] = true;
                mp[s[i]]--;
            }else{
                mp[s[i]]--;
            }
        }
        string res;
        while(!st.empty()){
            res+= st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }