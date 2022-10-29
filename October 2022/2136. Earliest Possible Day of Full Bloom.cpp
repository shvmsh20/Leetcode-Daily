int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
         int max_bloom_time = INT_MIN;
        vector<pair<int,int>> grow_plant_times;
        
        for(int i=0;i<plantTime.size();i++) {
            grow_plant_times.push_back({growTime[i], plantTime[i]});
        }
        
               
        sort(grow_plant_times.begin(),grow_plant_times.end(),greater<pair<int,int>>());
        
       
        int prev_plant_time = 0;
        
        for(int i=0;i<grow_plant_times.size();i++) {
            int grow_time = grow_plant_times[i].first;
            int plant_time = grow_plant_times[i].second; 
        
            prev_plant_time += plant_time; 
            
            int bloom_time = prev_plant_time + grow_time + 1; 
            
            max_bloom_time = max(max_bloom_time, bloom_time);
        }
        
        return max_bloom_time - 1; 
    }