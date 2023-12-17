struct myComp {
    bool operator()(
        pair<string, int> const& a,
        pair<string, int> const& b)
        
    {   if(a.second!=b.second){
        return a.second < b.second;
        }else{
        return a.first>b.first;
    }
        
    }
};
    unordered_map<string, priority_queue<pair<string, int>, vector<pair<string, int>>, myComp>> mp2;
    unordered_map<string, string> mp1;
    unordered_map<string, unordered_map<string, int>> mp3;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0; i<n; i++){
            mp3[cuisines[i]][foods[i]] = ratings[i];
            mp1[foods[i]] = cuisines[i];
             mp2[cuisines[i]].push({foods[i], ratings[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string t = mp1[food];
        mp3[t][food] = newRating;
        mp2[t].push({food, newRating});
    }
    
    string highestRated(string cuisine) {
        while(true){
            auto x = mp2[cuisine].top();
            if(x.second==mp3[cuisine][x.first]){
                return x.first;
            }else{
                mp2[cuisine].pop();
            }
        }
        
        
    }