unordered_map<int, pair<string, int>> entry;
    unordered_map<string, vector<int>> exit;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        entry[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> p = entry[id];
        entry.erase(id);
        string key = p.first+"#"+stationName;
        int time = t-p.second;
        exit[key].push_back(time);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "#" + endStation;
        double res;
        for(int i=0; i<exit[key].size(); i++){
            res+= exit[key][i];
        }
        res = (1.00*res)/exit[key].size();
        return res;
    }