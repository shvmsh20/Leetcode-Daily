int furthestBuilding(vector<int>& heights, int b, int l) {
        priority_queue<int> pq;
        int n = heights.size(), i;
        for(i=0; i<n-1; i++){
            if(heights[i]>=heights[i+1]){
                continue;
            }
            int x = heights[i+1]-heights[i];
            if(b>=x){
                b-= x;
                pq.push(x);
            }else if(l!=0){
                if(!pq.empty() && pq.top()>x){
                    b+= (pq.top()-x);
                    l--;
                    pq.pop();
                    pq.push(x);
                }else{
                    l--;
                }
            }else{
                break;
            }
        }
        return i;
    }