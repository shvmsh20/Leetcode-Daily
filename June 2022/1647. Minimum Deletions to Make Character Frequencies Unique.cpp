int minDeletions(string s) {
        int n = s.size();
        map<char, int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        priority_queue<int> pq;
        for(auto x: mp){
            pq.push(x.second);
        }
        int count=0;
        set<int> st;
        while(!pq.empty()){
            int curr = pq.top();
            pq.pop();
            if(st.find(curr)!=st.end()){
                int smallest = *(st.begin());
                if(smallest==0){
                    count+=curr;
                    continue;
                }
                int new_num = smallest-1;
                count+= (curr-new_num);
                st.insert(new_num);
            }else{
                st.insert(curr);
            }
        }
        return count;
    }