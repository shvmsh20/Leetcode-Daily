bool isNStraightHand(vector<int>& hand, int gpS) {
        int n = hand.size();
        if(n%gpS!=0){
            return false;
        }
        unordered_map<int, int> mp;
        set<int> s;
        for(int i=0; i<n; i++){
            mp[hand[i]]++;
        }
        for(auto x: mp){
            s.insert(x.first);
        }
        while(s.empty()==false){
            int first = *(s.begin());
            for(int i=0; i<gpS; i++){
                int num = i+first;
                if(s.find(num)==s.end()){
                    return false;
                }
                mp[num]--;
                if(mp[num]==0){
                    s.erase(num); 
                }
            }
        }
        