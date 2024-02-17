int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = heights.size(), lstHeight = heights[0];
        for(int i=1; i<n; i++){ 
            if(heights[i]<=lstHeight){
                lstHeight = heights[i];
                continue;
            }
            int diff = heights[i] - lstHeight;
            pq.push(diff);
            bricks-=diff;
            if(bricks<0){
                if(ladders==0){
                    return i-1;
                }else{
                    bricks+= pq.top();
                    pq.pop();
                    ladders--;
                }
            }

            lstHeight = heights[i];
        }
        return n-1;
        
    }