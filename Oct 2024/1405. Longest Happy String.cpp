struct cmp{
        bool operator()(pair<int, char> &p1, pair<int, char> &p2){
            return p1.first<p2.first;
        }
    };
    string longestDiverseString(int a, int b, int c) {
        string res;
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});
        char prevTop = 'x', prev = 'y';
        while(!pq.empty()){
            pair<int, char> p1 = pq.top();
            pq.pop();
            if(p1.second==prev && p1.second==prevTop){
                if(pq.empty()){
                    return res;
                }
                pair<int, char> p2 = pq.top();
                pq.pop();
                res.push_back(p2.second);
                p2.first--;
                if(p2.first){
                    pq.push(p2);
                }
                pq.push(p1);
            }else{
                p1.first--;
                res+= p1.second;
                if(p1.first){
                    pq.push(p1);
                }
            }
            prevTop = prev;
            prev = res.back();
        }
        return res;
    }