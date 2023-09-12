int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(char x: s){
            mp[x]++;
        }
        priority_queue<int> pq;
        for(auto x: mp){
            pq.push(x.second);
        }
        int mn = INT_MAX, res = 0;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            if(mn==INT_MAX){
                mn = x;
            }else if(mn<=x){
                if(mn!=0){
                    res+= (x-mn+1);
                }else{
                    res+=x;
                }
                
                mn = max(0, mn-1);
            }else{
                mn = x;
            }
           
                
        }
        return res;
    }