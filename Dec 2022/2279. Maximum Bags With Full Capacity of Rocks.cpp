int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        vector<int> v(n);
        for(int i=0; i<n; i++){
            v[i] = capacity[i] - rocks[i];
        }
        int count=0;
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++){
            
            if(v[i]==0){
                count++;
            }
            else if(additionalRocks>=v[i]){
                
                additionalRocks-=v[i];
                count++;
            }
        }
        return count;
    }